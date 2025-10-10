#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 2e5+1;
vector<int> g[N], bigchild(N, -1);
int last[N], pos[N], depth[N], parent[N], chain[N], sub[N];
int tree[4*N];
int n, timer, mx;
 
void dfs(int v, int p){
	mx = -1; sub[v] = 1;
	
	for(auto to : g[v]){
		if(to == p) continue;
		depth[to] =depth[v]+1;
		parent[to] = v;
		dfs(to, v);
		sub[v]+= sub[to];
		if(mx < sub[to]){
			bigchild[v] = to;
			mx = sub[to];
		}
	}
}
 
void decompose(int v, int head, int p){
	pos[v] = timer++;
	chain[v] = head;
	if(bigchild[v] != -1){
		decompose(bigchild[v], head, v);
	}
	for(auto to : g[v]){
		if(to == p or to == bigchild[v]) continue;
		decompose(to, to, v);
	}
}
 
int lca(int a, int b){
	for(; chain[a] != chain[b]; b = parent[chain[b]]){
		if(depth[chain[a]] > depth[chain[b]]) swap(a, b);
	}
	if(depth[a] > depth[b]) swap(a, b);
	return a;
}
 
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cur[n + 1];
	
	
	depth[1] = 0, parent[1] = 1;
	dfs(1, 1);
	decompose(1, 1, 1);
	for(int i = 1;i <= n; i++){
		cur[pos[i]] = i;
	}
//	for(int i = 0;i < n; i++){
//		cout << cur[i] << " ";
//	}
//	cout << endl;
	while(q--){
		int a, b; cin >> a >> b;
		int parent = lca(a, b);
		cout << depth[a] + depth[b] - depth[parent]*2 << "\n";
	}
	return 0;
}