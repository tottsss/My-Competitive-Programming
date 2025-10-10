#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int LOG = 25;
vector<int> g[N+10];
int up[N+10][LOG+1],depth[N+10];
vector< vector<int> > up_min(N+10, vector<int>(LOG+1, INT_MAX));
int n, q;
void dfs(int v, int p){
	up[v][0] = p;
	for(int i = 1;i < LOG; i++){
		up[v][i] = up[up[v][i-1]][i-1];
		up_min[v][i] = min({up_min[v][i-1], up_min[up[v][i-1]][i-1]});
	}
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
	}
}
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	for(int i = 0;i < LOG; i++){
		if(d& (1 << i)){
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}
int min_edge(int a, int k){
	int ans = INT_MAX;
	for(int i = 0;i < LOG; i++){
		if(k & (1<<i)){
			ans = min(ans, up_min[a][i]);
			a = up[a][i];
		}
	}
	return ans;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2;i <= n; i++){
		int a, b; cin >> a >> b;
		up_min[i][0] = b;
		g[i].push_back(a);
		g[a].push_back(i);
	}
	dfs(1, 1);
	cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		int lc = lca(x, y);
		int minimum = min_edge(x, depth[x]-depth[lc]);
		minimum = min(minimum, min_edge(y, depth[y] - depth[lc]));
		cout << minimum << '\n';
	}
	return 0;
}

