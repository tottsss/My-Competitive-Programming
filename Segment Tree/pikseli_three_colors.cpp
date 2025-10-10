#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1000000;
const int M = 2019;
struct node{
	int one, two, lazy;
};
struct paint{
	int l, r, z;
};
vector<paint> g[N+10];
node tree[4*N + 10];
void push(int v, int vl, int vr){
	if(tree[v].lazy == -1) return;
	if(tree[v].lazy==0){
		tree[v].one = tree[v].two = 0;	
	}else if(tree[v].lazy == 1){
		tree[v].one = vr-vl+1, tree[v].two=0;
	}else if(tree[v].lazy == 2){
		tree[v].two = vr-vl+1, tree[v].one = 0;
	}
	if(vl != vr){
		tree[v<<1].lazy = tree[v].lazy, tree[v<<1|1].lazy = tree[v].lazy;
	}
	tree[v].lazy = -1;
}

void update(int l, int r, int z,  int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		tree[v].lazy = z;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, z,  v<<1, vl, mid);
	update(l, r, z, v<<1|1, mid+1, vr);
	tree[v].one = tree[v<<1].one + tree[v<<1|1].one;
	tree[v].two = tree[v<<1].two + tree[v<<1|1].two;
}
// KRSU 1042
// this code is wrong
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0;i <= 4*N; i++){
		tree[i] = {0, 0, -1};
	}
	for(int i = 0;i < n; i++){
		int a, b, c, d, z; cin >> a >> b >> c >> d >> z;
		g[min(a, c)].push_back({min(b, d), max(b, d), z});
		g[max(a, c)+1].push_back({min(b, d), max(b, d), 0});
	}
	int ans = 0;
	for(int i = 1;i <= N; i++){
		for(paint x : g[i]){
			update(x.l, x.r, x.z, 1, 1, N);
		}
		push(1, 1, N);
		ans = (ans + tree[1].one)%M;
	}
	cout << ans;
	return 0;
}

