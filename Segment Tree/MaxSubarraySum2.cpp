#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 2e5;
const int mod = 1e15;
int n, q, a[N+10], pref[N+10];
int Left, Right;


struct node{
	int sum, mn, mx;
//	int sum = 0, mn = mod, mx = -mod;
};
vector<node> tree;
node combine(node a,node b){
	return {
		a.sum+b.sum, min(a.mn, b.mn), max(a.mx, b.mx)
	};
}
node new_node(int x){
	return{x, x, x};
}
void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = new_node(x);
	}else{
		int  mid = (vl + vr)>>1;
		if(mid>= pos) update(pos, x, v<<1, vl, mid);
		else update(pos, x, v<<1|1, mid+1, vr);
		tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	}
}
node calc(int l, int r, int v, int vl, int vr){
	if(r < l) return {0LL, mod, -mod};
	if(l > vr or vl > r) return {0LL, mod, -mod};
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	node L = calc(l, r, v<<1, vl, mid);
	node R = calc(l, r, v<<1|1, mid+1, vr);
	return combine(L,R);
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> Left >> Right;
	tree.resize(4*N, {0, mod, -mod});
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
	}
	int mx = -mod;
	for(int i = 1;i <= n; i++){
		
		pair<int, int> range;
		range = {i-Right,i - Left};
		if(range.ff <= 0) range.ff = 1;
		if(range.ss >= i) range.ss = i;
		if(i >= Left && i <= Right) mx = max(mx, pref[i]);
		node res = calc(range.ff, range.ss, 1, 1, n);
		mx = max(mx, pref[i] - res.mn);
		update(i, pref[i], 1, 1, n);
	}
	cout << mx;
	
	
	return 0;
}