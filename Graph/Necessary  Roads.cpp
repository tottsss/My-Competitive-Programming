#include <bits/stdc++.h>
using namespace std;
 
main(){
	int n, m; cin >> n >> m;
	vector<int> g[n + 1];
	vector<int> in(n + 1, 0), up(n + 1, 0), used(n + 1, 0);
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set< pair<int, int> > Bridge;
	int Timer = 0;
	function<void(int, int )> Tarzan=[&](int v, int p){
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
			Bridge.insert({min(v, p), max(v,p)});
		}
		
	};
	
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			Tarzan(i, -1);
		}
	}
	cout << Bridge.size() << "\n";
	for(auto x : Bridge){
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}