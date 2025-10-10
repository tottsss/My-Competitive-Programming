#include "bits/stdc++.h"
using namespace std;
const int N = 1e6+1;
vector<int> g[N], euler, depth(N,0), pos(N,-1), deep;
pair<int, int> tree[2*N];
int siz = 1;
 
void init(int n){
	while(siz < n) siz*= 2;
}
 
void dfs(int v, int p){
	euler.push_back(v);
	for(auto to : g[v]){
		if(p == to) continue;
		depth[to] = depth[v] + 1;
		dfs(to, v);
		euler.push_back(v);
	}
}
 
void build(int v, int vl, int vr){
	if(vl == vr){
		if(vl > euler.size()) tree[v] = {INT_MAX, INT_MAX};
		else
		tree[v] = {deep[vl], vl};
		return;
	}
	int mid = (vl + vr) / 2;
	build(v+v, vl, mid);
	build(2*v+1, mid+1, vr);
	tree[v] = min(tree[2*v], tree[2*v+1]);
}
 
pair<int, int> get(int l, int r, int v, int vl, int vr){
	if(vl > r or l > vr) return {INT_MAX, 0};
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr) / 2;
	return min(get(l, r, 2*v, vl, mid), get(l, r, 2*v+1, mid+1, vr));
}
 
 
 
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 2;i <= n; i++){
		int par; cin >> par;
		g[par].push_back(i);
	}
	euler.push_back(1);
	
	
	dfs(1, -1);
	for(int i = 0;i < euler.size(); i++){
		deep.push_back(depth[euler[i]]);
		if(pos[euler[i]] == -1){
			pos[euler[i]] = i;
		}
	}
	init(euler.size());
	build(1, 1, siz);
	while(q--){
		int a, b; cin >> a >> b;
		int l = min(pos[a], pos[b]);
		int r = max(pos[a], pos[b]);
		cout << euler[get(l, r, 1, 1, siz).second] << "\n";
	}
	return 0;
}