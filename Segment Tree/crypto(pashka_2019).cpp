#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
struct vec{
	int ve[2][2];
};
const int N = 2e5 + 1;
int mod, n, m;
vector< vec > A(N);
vector< vec > tree;
vec zero;
int sz;

void init(){
	while(n > sz) sz*= 2;
	tree.resize(sz*2 + 1);
}

vec mul(vec &a, vec &b){
	vec C;
	for(int i = 0;i < 2; i++){
		for(int j = 0;j < 2; j++){
			C.ve[i][j] = 0;
			for(int k = 0;k < 2; k++){
				C.ve[i][j]= (C.ve[i][j] + (a.ve[i][k] * b.ve[k][j])) % mod;
			}
		}
	}
	return C;
}
void build(int v,int vl, int vr){
	if(vl == vr){
		if(vl >= n) tree[v] = zero;
		else
		tree[v] = A[vl];
	}else{
		int mid =(vl+vr)>>1;
		build(v<<1|1, vl, mid);
		build((v<<1) + 2, mid+1, vr);
		tree[v] = mul(tree[v<<1|1], tree[(v<<1) + 2]);
	}
}

vec query(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return zero;
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	vec a = query(l, r, v<<1|1, vl, mid);
	vec b = query(l, r, (v<<1) + 2, mid+1, vr);
	return mul(a,b);
}


main(){
	ifstream cin("crypto.in");
	ofstream cout("crypto.out");
	cin >> mod  >> n >> m;
	zero.ve[0][0] = 1;
	zero.ve[0][1] = 0;
	zero.ve[1][0] = 0;
	zero.ve[1][1] = 1;
	for(int k = 0; k < n; k++){
		for(int i = 0;i < 2; i++){
			for(int j = 0;j < 2; j++){
				cin >> A[k].ve[i][j];
				A[k].ve[i][j]%= mod;
			}
		}
	}
	sz = 1;
	init();
	build(0, 0, sz);
	while(m--){
		int L, R; 
		cin >> L >> R;
		L--, R--;
		vec ans = query(L, R, 0, 0, sz);
		for(int i = 0;i < 2; i++){
			for(int j = 0; j < 2; j++){
				cout << ans.ve[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		
	}
	return 0;
}

