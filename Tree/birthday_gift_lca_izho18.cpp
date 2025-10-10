#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int LOG = 25;
int up[N + 1][LOG], depth[N+1];
vector<int> g[N+1];
vector< set<int> > LCA(N+1);
vector< set<int> > where(N+1);
int n, m, q;
vector<int> a;
void dfs(int v, int p){
	up[v][0] = p;
	for(int j = 1;j < LOG; j++){
		up[v][j] = up[up[v][j-1]][j-1];
	}
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
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
	if(a == b) return b;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	a.resize(m);
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < m; i++){
		cin >> a[i];
		where[a[i]].insert(i);
	}
	dfs(1, 1);
	for(int i = 0;i < m-1; i++){
		LCA[lca(a[i], a[i+1])].insert(i);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int pos, v; cin >> pos >> v; pos--;
			if(pos < m-1){
				LCA[lca(a[pos], a[pos+1])].erase(pos);
				LCA[lca(v, a[pos+1])].insert(pos);
			}
			if(pos > 0){
				LCA[lca(a[pos], a[pos-1])].erase(pos-1);
				LCA[lca(v, a[pos-1])].insert(pos-1);
			}
			where[a[pos]].erase(pos);
			a[pos] = v;
			where[v].insert(pos);
		}else{
			int l, r, v; cin >> l >> r >> v; l--, r--;
			auto it = where[v].lower_bound(l);
			if(it != where[v].end() and *it >= l and *it <= r){
				cout << *it+1 << ' ' << *it+1 << '\n';
				continue;
			}
			it = LCA[v].lower_bound(l);
			if(it != LCA[v].end() and *it >=l and *it < r){
				cout << *it+1 << ' ' << *it+2 << '\n';
				continue;
			}
			cout << "-1 -1" << '\n';
		}
	}
	return 0;
}

