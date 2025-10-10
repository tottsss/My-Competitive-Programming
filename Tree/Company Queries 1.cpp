#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
const int LOG = 20;
int up[N][LOG];
int depth[N];
vector<int> g[N];
 
void dfs(int v, int par){
	for(auto to : g[v]){
		if(to == par) continue;
		depth[to] = depth[v] + 1;
		up[to][0] = v;
		for(int j = 1;j < LOG; j++){
			up[to][j] = up[ up[to][j-1] ][j-1];
		}
		dfs(to, v);
	}
}
 
int get_lca(int a, int b){
	if(depth[b] > depth[a]) swap(a, b);
	int k = depth[a] - depth[b];
	for(int i = LOG-1; i >= 0; i--){
		if(k  & (1 << i)){
			a = up[a][i];
		}
	}
	if(a == b) return a;
	for(int j = LOG -1; j >= 0; j--){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}
 
main(){
	int n, q; cin >> n >> q;
	for(int i = 2;i <= n ; i++){
		int par; cin >> par;
		g[par].push_back(i);
	}
	depth[1] = 0;
	dfs(1, -1);
	while(q--){
		int a, k; cin >> a >> k;
		for(int i = LOG-1; i >= 0; i--){
			if(k  & (1 << i)){
				a = up[a][i];
			}
		}
		if(a == 0) cout << -1 << "\n";
		else
		cout << a << "\n";
		
	}
 
	return 0;
}