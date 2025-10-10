#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
const int N = 1e5;

int up[N+1][20], depth[N+1], value[N+1];
vector<int> g[N+1];
map<pair<int, int>, int> mp;
vector<pair<int, int> > edge;
int n, q;
void dfs(int v, int p){
	up[v][0] = p;
	for(int i = 1;i < 20; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] =depth[v]+1;
		dfs(to, v);
	}
}
void dfs_ans(int v, int p){
	int sum = value[v];
	for(int to : g[v]){
		if(to == p) continue;
		dfs_ans(to, v);
		sum+= value[to];
	}
	value[v] = sum;
}
void dfs_edge(int v, int p){
	for(int to : g[v]){
		if(to == p) continue;
		mp[make_pair(to, v)]+=  value[to];
		mp[make_pair(v, to)]+= value[to];
		dfs_edge(to, v);
	}
}
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	for(int i = 0;i < 20; i++){
		if(d & (1<<i)) b = up[b][i];
	} 
	if(a == b) return a;
	for(int i = 19; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		edge.push_back({a, b});
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> q;
	dfs(1, 1);
	while(q--){
		int a, b; cin >> a >> b;
		int common = lca(a, b);
		value[common]-= 2, value[a]++, value[b]++;
	}
	dfs_ans(1, 1);
	dfs_edge(1, 1);
	for(pair<int, int> x : edge){
		cout << mp[x] << " ";
	}
	return 0;
}

