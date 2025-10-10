#include <bits/stdc++.h>
using namespace std;
 
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> g[n + 1], G[n + 1], used(n + 1, 0);
	vector<int> topolog;
	vector< pair<int, int> > edge;
	map<pair<int, int>, int> mp;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	function<void(int, int)> dfs=[&](int v, int p){
		used[v] = 1;
		for(auto to : g[v]){
			if(mp.count({to, v}) ==false){
				edge.push_back({v,to});
				mp[{to, v}] = 1;
				mp[{v, to}] = 1;
			}
			if(used[to] == 0){
				dfs(to, v);
			}
		}
		topolog.push_back(v);
	};
	dfs(1, 1);
	if(topolog.size() != n or edge.size() != m){
		cout << "IMPOSSIBLE";
		exit(0);
	}
	reverse(topolog.begin(), topolog.end());
	for(auto x : edge){
		G[x.second].push_back(x.first);
	}
	for(int i = 1;i <= n; i++) used[i] = 0;
	function<void(int)> TO=[&](int v){
		used[v] = 1;
		for(auto to : G[v]){
			if(used[to] == 0){
				TO(to);
			}
		}
	};
	TO(topolog[0]);
	
	if(count(used.begin(), used.end(), 1) >= n){
		for(auto x : edge){
			cout << x.first << ' ' << x.second << '\n';
		}
	}else{
		cout << "IMPOSSIBLE";
	}
	return 0;
}