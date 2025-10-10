#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

// https://contest.nlogn.info/contest/3855/problems/A


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> c(n), g[n];
	vector< vector<int> > dp(n, vector<int>(2, 0));
	for(int i = 0;i < n; i++){
		cin >> c[i];
	}
	int a, b;
	for(int i = 1;i <= n; i++){
		cin >> a >> b;
		if(a == 0 and b == 0) break;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	
	function<void(int, int)> dfs=[&](int v, int par){
		int sum = 0;
		for(int to : g[v]){
			if(to == par) continue;
			dfs(to, v);
			dp[v][0]+= dp[to][1];
			sum+= dp[to][0];
		}	
		dp[v][1] = max(dp[v][0], sum + c[v]);
	};
	
	dfs(0, 0);
	cout << dp[0][1];
	return 0;
}

