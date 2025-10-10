#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 2e5+1;
const int LOG = 25;
vector<int> g[N];
int up[N][LOG];
int sub[N], mark[N], depth[N];
int centroid_par[N], Distance[N];
int n;
int calc_sizes(int v, int p){
	sub[v] = 1;
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		sub[v]+= calc_sizes(to, v);
	}
	return sub[v];
}
int find_centroid(int v, int p, int sz){
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		if(sub[to] > sz/2){
			return find_centroid(to, v, sz);
		}
	}
	return v;
}
 
void calc_lca(int v, int p){
	up[v][0] = p;
	for(int j = 1; j < LOG; j++){
		up[v][j] = up[up[v][j-1]][j-1];
	}
	for(int to : g[v]){
		if(to != p){
			depth[to] = depth[v]+1;
			calc_lca(to, v);
		}
	}
} 
 
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int k = depth[b]-depth[a];
	for(int i = 0;i < LOG; i++){
		if(k&(1<<i)){
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i = LOG-1; i >=0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
} 
 
 
int dist(int a, int b){
	int parent = lca(a, b);
	return depth[a]+depth[b]-2*depth[parent];
} 
 
void decompose(int centroid, int par_centroid){
	mark[centroid] = 1;
	centroid_par[centroid] = par_centroid;
	for(int to : g[centroid]){
		if(mark[to] or to == par_centroid){
			continue;
		}
		calc_sizes(to, to);
		decompose(find_centroid(to, to, sub[to]), centroid);
	}
}
void paint(int v){
	for(int path = v; path != -1; path = centroid_par[path]){
		Distance[path] = min(Distance[path], dist(path, v));
	}
} 
int query(int v){
	int D = INT_MAX;
	for(int path = v; path != -1; path = centroid_par[path]){
		D = min(D, Distance[path] + dist(path, v));
	}
	return D;
}
void solve(){
	cin >> n;
	vector<int> c(n);
	for(int i = 0;i < n; i++) cin >> c[i];
	for(int i = 1;i <= n; i++){
		g[i].clear();
		mark[i] = 0,sub[i] = 0, depth[i] = 0, centroid_par[i] = -1;
		Distance[i] = INT_MAX;
	}
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	calc_lca(c[0], c[0]);
	calc_sizes(c[0], c[0]);
	int centre = find_centroid(c[0], c[0], sub[c[0]]);
	decompose(centre, -1);
	paint(c[0]);
	int min_distance = INT_MAX;
	for(int i = 1;i < n; i++){
		min_distance = min(min_distance, query(c[i]));
		paint(c[i]);
		cout << min_distance << ' ';
	}
}
main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	return 0;
}