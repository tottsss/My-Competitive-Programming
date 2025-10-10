#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int MAX = LLONG_MAX;
const int N = 1e5;
const int LOG = 17;
int n, s, q, e;
vector< pair<int, int> > g[N + 1];
vector< pair<int, int> > edges;
int is_shop[N+1], up[N+1][LOG+2], depth_sum[N+1];
int depth[N+1], tin[N+1], tout[N+1], range[N+1];
int timer, T;
int euler[N * 2 + 100];
int lg[N*2 + 100], dist_shop[N + 10];
int lst[N*2+100];
void dfs(int v, int par){
	tin[v] = timer++;
	range[v] = T;
	lst[v] = T;
	euler[T++] = v;
	up[v][0] = par;
	for(int j = 1;j <= LOG; j++){
		up[v][j] = up[up[v][j-1]][j-1];
	}
	int distance = MAX;
	for(auto [to, w] : g[v]){
		if(to == par) continue;
		depth[to] = depth[v] + 1;
		depth_sum[to] = depth_sum[v] + w;
		dfs(to, v);
		lst[v] = T;
		euler[T++] = v;
		distance = min(distance, dist_shop[to] + w);
	}	
	if(is_shop[v]){
		dist_shop[v] = 0;
	}else{
		dist_shop[v] = distance;
	}
	tout[v] = timer;
}
int is_parent(int par, int v){
	return (tin[par] <= tin[v] && tout[v] <= tout[par]);
}
int sparse[LOG+3][N * 2+10];
int query_rmq(int a, int b) {
	if(a > b) swap(a, b);
	int f = lg[b-a + 1];
//	if(a == b) return sparse[f][a].ff;
	return min(sparse[f][a],sparse[f][b - (1<<f) + 1]);
}
int min_on_way(int u, int v) {
	if(is_parent(u, v)) swap(u, v);
	return query_rmq(range[u], lst[v]);
}
int close(int idx){
	return (depth[edges[idx].ff] < depth[edges[idx].ss] ? edges[idx].ss : edges[idx].ff);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> s >> q >> e;
	edges.push_back({-1, -1});
	for(int i = 1;i < n; i++){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
		edges.push_back({a, b});
	}
	for(int i = 0;i < s; i++){
		int x; cin >> x;
		is_shop[x] = 1;
	}
	dfs(e, e);
	for(int i = 0;i < T; i++){
		sparse[0][i] = {dist_shop[euler[i]] - depth_sum[euler[i]]};
	}
	int logT = 0;
	while ((1<<logT) < T) logT++;
	for(int f = 0; f < logT; f++){
		for(int i = 0;i + (1<<f) < T; i++){
			sparse[f+1][i] = min(sparse[f][i], sparse[f][i + (1<<f)]);
		}
	}
	lg[0] = 0;
	for(int i = 2;i < T; i++){
		lg[i] = lg[i / 2] + 1;
	}
	while(q--){
		int idx, v; cin >> idx >> v;
		if(!is_parent(close(idx), v)){
			cout << "escaped";
		}else{
			int mn = min_on_way(v, close(idx));
			if(mn != LLONG_MAX)
			mn+= depth_sum[v];
			mn = min(mn, dist_shop[v]);
			if(mn >= LLONG_MAX) cout << "oo";
			else cout << mn;
		}
		cout << '\n';
	}
	return 0;
}

