#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 +1;
vector<int> a(2 *N);
vector<int> tree(4 * N,0);
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
	if(k <= tree[2 * v + 1]){
		return find_k(k, v * 2 + 1, vl, mid);
	}else{
		return find_k(k - tree[v * 2+1], v*2+2, mid, vr);
	}
}

void setv(int i, int v, int vl, int vr){
        if(vr - vl == 1){
            tree[v] = 0;
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
	int A[n], P[n];
	int SIZ = n;
	for(int i = 0;i < n; i++){
		cin >> A[i];
		a[i] = 1;
	}
	init();
	build(0, 0, siz);
	for(int i = n-1; i >= 0; i--){
		int found = find_k(SIZ-A[i], 0, 0, siz);
		setv(found, 0, 0, siz);
		P[i] = found+1;
		SIZ--;
	}
	for(int i = 0;i < n; i++){
		cout << P[i] << " ";
	}
	return 0;
}
