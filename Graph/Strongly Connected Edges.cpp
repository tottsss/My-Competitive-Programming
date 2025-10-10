#include <bits/stdc++.h>
using namespace std;
 
main(){
	int n, m; cin >> n >> m;
	vector<int> g[n + 1];
	vector<int> in(n + 1, 0), up(n + 1, 0), used(n + 1, 0);
	vector< pair<int, int> > edge;
	map<pair<int, int>, int> mp;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int Timer = 0;
	function<void(int, int)> Tarzan=[&](int v, int p){
		used[v] = 1;
		up[v] = in[v] = Timer++;
		for(auto u : g[v]){
			if(used[u] == 0){
				Tarzan(u, v);
				up[v] = min(up[u], up[v]);
			}else if(u != p){
				up[v] = min(in[u], up[v]);
			}
		}
		if(p != -1 and up[v] == in[v]){
			cout << "IMPOSSIBLE";
			exit(0);
		}	
	};
	Tarzan(1, -1);
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			cout << "IMPOSSIBLE";
			exit(0);
		}
		used[i] = 0;
	}
	function<void(int, int)> dfs=[&](int v, int p){
		used[v] = 1;
		for(auto to : g[v]){
			if(to != p and mp.count({to, v}) ==false){
				edge.push_back({v,to});
				mp[{to, v}] = 1;
				mp[{v, to}] = 1;
			}
			if(used[to] == 0){
				dfs(to, v);
			}
		}
	};
	dfs(1, 1);
	if(edge.size() != m){
		cout << "IMPOSSIBLE";
		exit(0);
	}
	for(auto e : edge){
		cout << e.first << ' ' << e.second << '\n';
	}
	
	return 0;
}