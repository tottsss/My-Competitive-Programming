#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
const int N = 2*1e5+1;
vector<int> value, tree(4*N), g[N], node, sub(N, 1), subtree;
int siz;
int a[N];
void init(int n){
	siz = 1LL;
	while(n > siz) siz*= 2LL;
}
 
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = value[vl];
		// cout << tree[v] << " ";
		return;
	}
	int mid = (vl + vr)/2;
	build(v * 2 +1, vl, mid);
	build(v * 2 + 2, mid+1, vr);
	tree[v] = tree[v * 2+1] + tree[2*v+2];
}
 
int sum(int l, int r, int v, int vl, int vr){
	if(l > vr || vl > r) return 0;
	if(l <= vl and r >= vr) return tree[v];	
	
	 int mid = (vl + vr) / 2;
	 int L = sum(l, r, 2*v+1, vl, mid);
	 int R = sum(l, r, 2*v+2, mid+1, vr);
	 return (L + R);
}
 
void update(int k, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr) / 2;
	if(mid >= k){
		update(k, x, v*2+1, vl, mid);
	}else{
		update(k, x, 2*v+2, mid+1, vr);
	}
	tree[v] = tree[2*v+1] + tree[2*v+2];
}
 
void dfs(int v, int par){
	node.push_back(v);
	for(auto to : g[v]){
		if(to == par) continue;
		dfs(to, v);
		sub[v]+= sub[to];
	}
}
 
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
 
	init(n);
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 0;i < n-1; i++){
		int u, b; cin >> u >> b;
		g[u].push_back(b);
		g[b].push_back(u);
	}
	dfs(1, -1);
	map<int, int> mp;
	int idx = 0;
	for(auto to : node){ 
		mp[to] = idx;
		subtree.push_back(sub[to]);
		value.push_back(a[to]);
		idx++;
	}
	// for(auto to : node) cout << to << " ";
	// cout << "\n";
	 // for(auto to : subtree) cout << to << " ";
	  // cout << "\n";
	 build(0, 0, siz);
	 // for(int i = 0;i < siz; i++) cout << tree[i] << " ";
	 // cout << "\n";
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int s, x; cin >> s >> x;
			update(mp[s], x, 0, 0, siz);
		}else{
			int s; cin >> s;
			int l = mp[s];
			int r = l + subtree[mp[s]] - 1;
			 // cout << l << " " << r;
			   cout << sum(l, r, 0, 0, siz) << "\n";
		}
		// cout << "\n";
	}
	return 0;
}