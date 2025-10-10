#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 50000 + 10;
const int LOG = 20;
int n, q;
vector<pair<int, int> > g[N];
int depth[N], sum[N];
int up[N][LOG];
void dfs(int v, int p){
	up[v][0] = p;
	for(int i = 1;i < LOG; i++){
		up[v][i] =up[up[v][i-1]][i-1];
	}
	for(auto to : g[v]){
		if(p == to.ff) continue;
		depth[to.ff] = depth[v]+1;
		sum[to.ff] = sum[v]+to.ss;
		dfs(to.ff, v);
	}
}

int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a,b);
	int k = depth[b]-depth[a];
	for(int i = 0;i < LOG; i++){
		if(k&(1<<i)) b = up[b][i];
	}
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}

int distance(int a, int b){
	int LCA = lca(a, b);
	return (sum[a] + sum[b] - 2*sum[LCA]);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b, c; cin >> a >> b >> c;
		a++, b++;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	dfs(1, 1);
	cin >> q;
	while(q--){
		int a, b; cin >> a >> b; a++, b++;
		cout << distance(a, b) << '\n';
	}
	return 0;
}

