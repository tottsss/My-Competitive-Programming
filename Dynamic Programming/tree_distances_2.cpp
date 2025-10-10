#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> g[n], sub(n, 1), ans(n, 0);
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	function<void(int, int, int)> subtree_size=[&](int v, int p, int deep){
		ans[0]+= deep;
		for(int to : g[v]){
			if(to == p) continue;
			subtree_size(to, v, deep+1);
			sub[v]+= sub[to];
		}
	};
	subtree_size(0, 0, 0);
	function<void(int, int)> dfs=[&](int v, int p){
		for(int to : g[v]){
			if(to == p) continue;
			ans[to] = ans[v] + n - sub[to] - sub[to];
			dfs(to, v);
		}
	};
	dfs(0, 0);
	for(int i = 0;i < n; i++) cout << ans[i] << ' ';
	return 0;
}

