#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
vector<int> g[N+1];
int in[N+1], Up[N+1], T, used[N+1], idx[N+1];
map<pair<int, int>, int > mp;
vector<pair<int, int> > bridge;

int n, m;
void dfs(int v, int p){
	used[v] = 1;
	in[v] = Up[v] = ++T;
	for(int to : g[v]){
		if(used[to] == 0){
			dfs(to, v);
			Up[v] = min(Up[v], Up[to]);
		}else if(to != p){
			Up[v] = min(Up[v], in[to]);
		}
	} 
	if(v != p and in[v] <= Up[v]){
		mp[{min(v, p), max(v, p)}]--;
		bridge.push_back({min(v, p), max(v, p)});
	}
}
int comp = 1;
void dfs_2(int v){
	used[v] = 1, idx[v] = comp;
	for(int to : g[v]){
		if(used[to]) continue;
		if(mp[{min(v, to), max(v,to)}]){
			dfs_2(to);
		}
	}
}
vector<int> tree[N+1];
int up[N+1][20], depth[N+1];


void dfs_tree(int v, int p){
	up[v][0] = p;
	for(int j = 1;j < 20; j++){
		up[v][j] = up[up[v][j-1]][j-1];
	}
	for(int to : tree[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1; 
		dfs_tree(to, v);
	}
}

int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	for(int i = 0;i < 20; i++){
		if(d & (1<<i)){
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}

int distance(int a, int b){
	int lc = lca(a, b);
	return depth[a] + depth[b] - 2 * depth[lc];
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		mp[make_pair(min(a, b), max(a, b))]++;
	}
	dfs(1, 1);
	for(int i = 1;i <= n; i++) used[i] = 0;
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			dfs_2(i);
			comp++;
		}
	}
	for(auto e : bridge){
		tree[idx[e.ff]].push_back(idx[e.ss]);
		tree[idx[e.ss]].push_back((idx[e.ff]));
	}
	dfs_tree(1, 1);
	int q; cin >> q;
	while(q--){
		int a, b; cin >> a >> b;
		a = idx[a], b = idx[b];
		cout << distance(a, b) << '\n';
	}
	return 0;
}

