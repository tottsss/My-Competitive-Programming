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
	vector<int> cost(n, -100), g[n];
	vector<vector<int> > dp(n, vector<int>(2, -100));
	for(int i = 1; i < n; i++){
		char c; cin >> c;
		int p; cin >> p;
		p--;
		g[i].push_back(p);
		g[p].push_back(i);
		if(c == 'L'){
			int x; cin >> x;
			cost[i] = x;
		}
	}
	
	function<void(int, int)> dfs=[&](int v, int p){
		int lose1 = 0, draw1 = 0, win1 = 0;
		int lose = 0, draw = 0, win = 0;
		for(int to : g[v]){
			if(to == p) continue;
			dfs(to, v);
			lose+= (dp[to][1] == -1);
			draw+= (dp[to][1] == 0);
			win+= (dp[to][1] == 1);
			lose1+= (dp[to][0] == -1);
			draw1+= (dp[to][0] == 0);
			win1+= (dp[to][0] == 1);
		}	
		if(cost[v] == 0){
			dp[v][0] = 0, dp[v][1] = 0;
		}
		else if(cost[v] == -1){
			dp[v][0] = -1, dp[v][1] = 1;
		} 
		else if(cost[v] == 1){
			dp[v][0] = 1, dp[v][1] = -1;
		}
		else{
			if(lose > 0) dp[v][0] = 1;
			else if(draw > 0) dp[v][0] = 0;
			else dp[v][0] = -1;
			
			if(lose1 > 0) dp[v][1] = 1;
			else if(draw1 > 0) dp[v][1] = 0;
			else dp[v][1] = -1;
			
		}
	};
	dfs(0, 0);
	if(dp[0][0]>0) cout << '+';
	cout << dp[0][0];
	
	return 0;
}

