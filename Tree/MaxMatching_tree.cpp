#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int m; cin >> m;
	vector<int> c(n), g[n];
	vector<int> used(n, 0), pairs(n, 0);
	vector< vector<int> > dp(n, vector<int>(2, 0));
	vector<int> p(n);
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set<pair<int, int> > ans;
	function<void(int, int)> dfs=[&](int v, int par){
		int sum = 0;
		for(int to : g[v]){
			if(to == par) continue;
			dfs(to, v);
			sum+= dp[to][1];
			
		}
		dp[v][0] = sum;
		dp[v][1] = max(dp[v][1], dp[v][0]);
		for(int to : g[v]){
			if(to == par) continue;
			dp[v][1] = max(dp[v][1], sum-dp[to][1] + dp[to][0] + 1);
		}
		for(int to : g[v]){
			if(dp[v][1] == dp[v][0]) continue;
			if(to == par) continue;
			if(dp[v][1] == sum-dp[to][1]+dp[to][0]+1){
				if(used[v] == 0 and used[to] == 0){
					ans.insert({min(v, to)+1, max(v, to)+1});
					used[v] = 1, used[to] = 1;
					pairs[v] = to, pairs[to] = v;
				}else{
					ans.erase({min(pairs[v], v)+1, max(pairs[v], v)+1});
					ans.erase({min(pairs[to], to)+1, max(pairs[to], to)+1});
					ans.insert({min(v, to)+1, max(v, to)+1});
					pairs[v] = to, pairs[to] = v;
					used[v] = 1, used[to] = 1;
				}	
				break;
			}
		}
	};
	dfs(0, 0);
	cout << dp[0][1] << '\n';
	for(auto x : ans){
		cout << x.ff << ' ' << x.ss << '\n';
	}
	return 0;
}

