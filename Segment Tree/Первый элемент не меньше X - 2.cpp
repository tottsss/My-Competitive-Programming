#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 7;
const int N = 1e5 +1;
vector<int> a(2 *N);
vector<int> tree(4 * N, -INF);
int n;
int siz;
void init( ){
	siz = 1;
	while(n > siz)siz*= 2;
}

void build(int v, int vl, int vr){
	if(vr - vl == 1){
		tree[v] = a[vl];
		return;
	}
	int mid = (vl + vr)/2;
	build(v * 2 + 1, vl, mid);
	build(v * 2 + 2, mid, vr);
	tree[v] = max(tree[v *2 + 1],  tree[v *2+2] );
}
void setv(int i,int x, int v, int vl, int vr){
        if(vr - vl == 1){
            tree[v] = x;
            return;
        }
        int m = (vl + vr) / 2;
        if(i < m){
            setv(i,x, 2 * v + 1, vl, m);
        }else{
            setv(i,x, 2 * v + 2, m, vr);
        }
        tree[v] = max(tree[v *2 + 1], tree[v * 2 + 2]);
}

int find(int x,int l, int v, int vl, int vr){
	if(tree[v] < x) return -1;
	if(l >= vr) return -1;
	if(vr-vl == 1){
		return vl;
	}
	int mid = (vl + vr)/2;
	int L = find(x, l, 2 * v + 1,  vl, mid);
	if(L == -1){
		 L = find(x, l,  2 * v +2,mid, vr);
	}
	return L;
}

 main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	int q; cin >> q;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	init();
	build(0, 0, siz);
	while(q--){
		int c;
        cin >> c;
        if(c == 1){
            int i, x;
            cin >> i >> x;
            setv(i, x,  0, 0, siz);
        }else if(c== 2){
            int x; cin >> x;
            int l; cin >> l;
            cout << find(x, l,  0, 0, siz);
            cout << "\n";
        }
	}
	return 0;
}
