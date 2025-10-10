#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 +1;
vector<int> a(2 *N);
vector<int> tree(4 * N);
int n;
int siz;
void init( ){
	siz = 1;
	while(n > siz)siz*= 2;
	//tree.assign(2 * siz + 50, 0);
}

void build(int v, int vl, int vr){
	if(vr - vl == 1){
		tree[v] = a[vl];
		return;
	}
	int mid = (vl + vr)/2;
	build(v * 2 + 1, vl, mid);
	build(v * 2 + 2, mid, vr);
	tree[v] = tree[v *2 + 1] + tree[v *2+2];
}

int find_k(int k, int v, int vl, int vr){
	if(vr-vl == 1){
		return vl;
	}
	int mid = (vl + vr) / 2;
	if(k < tree[2 * v + 1]){
		return find_k(k, v * 2 + 1, vl, mid);
	}else{
		return find_k(k - tree[v * 2+1], v*2+2, mid, vr);
	}
}

void setv(int i, int v, int vl, int vr){
        if(vr - vl == 1){
            tree[v] = 1 - tree[v];
            return;
        }
        int m = (vl + vr) / 2;
        if(i < m){
            setv(i, 2 * v + 1, vl, m);
        }else{
            setv(i, 2 * v + 2, m, vr);
        }
        tree[v] = tree[v *2 + 1] + tree[v * 2 + 2];
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
            int i;
            cin >> i;
            setv(i, 0, 0, siz);
        }else if(c== 2){
            int k; cin >> k;
            cout << find_k(k, 0, 0, siz);
            cout << "\n";
        }
	}
	return 0;
}
