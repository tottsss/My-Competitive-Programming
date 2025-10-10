#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
vector<pair<int, int> > g[N+1];
int par[N+1], n, m;
vector<pair<pair<int, int> , pair<int, int> > > edge;
int depth[N+1];

int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	if(a == b) return;
	par[b] = a;
}
int up[N+10][25];
vector<vector<int> > la(N+10, vector<int>(25, INT_MIN));

void dfs(int v, int p, int cost){
	up[v][0] = p;
	la[v][0] = cost;
	for(int i = 1;i < 20; i++){
		up[v][i] = up[up[v][i-1]][i-1];	
		la[v][i] = max(la[v][i-1], la[up[v][i-1]][i-1]);
	} 
	for(auto [to, w] : g[v]){
		if(to == p) continue;
		depth[to] = depth[v] + 1;
		dfs(to, v, w);
	}
}

int go_k(int a, int k){
	for(int i = 0;i < 20; i++){
		if(k&(1<<i)) a = up[a][i];
	}
	return a;
}

int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	b = go_k(b, depth[b] - depth[a]);
	if(a == b) return a;
	for(int i = 19; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b	= up[b][i];
		}
	}
	return up[a][0];
}



int distance(int a, int b){
	int lc = lca(a, b);
	return depth[a] + depth[b] - 2*depth[lc];
}

int get_max(int a, int k){
	int ans = INT_MIN;
	for(int i = 0;i < 20; i++){
		if(k&(1<<i)){
			ans = max(ans, la[a][i]);
			a = up[a][i];
		}
	}
	return ans;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		edge.push_back({{w, i}, {a, b}});
	}
	for(int i = 1;i <= n; i++) par[i] = i;
	sort(all(edge));
	int mst = 0;
	set<int> edge_mst;
	for(int i =0;i < m; i++){
		auto x = edge[i];
		int a = x.ss.ff, b = x.ss.ss;
		int w = x.ff.ff; int idx = x.ff.ss;
		a = find_set(a), b = find_set(b);
		if(a == b) continue;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
		union_set(a, b);
		mst+= w;
		edge_mst.insert(idx);
	}
	dfs(1, 1, INT_MIN);
	vector<pair<int, int> > Q;
	for(int i = 0;i < m; i++){
		auto x = edge[i];
		int a = x.ss.ff, b = x.ss.ss;
		int w = x.ff.ff; int idx = x.ff.ss;
		if(edge_mst.count(idx)){
			Q.push_back({idx, mst});
			continue;
		}
		int lc = lca(a, b);
		int ans = max(get_max(a, depth[a] - depth[lc]), get_max(b, depth[b] - depth[lc]));
		Q.push_back({idx, mst + abs(ans - w)});
	}
	sort(all(Q));
	for(auto x : Q){
		cout << x.ss <<  '\n';
	}
	return 0;
}

