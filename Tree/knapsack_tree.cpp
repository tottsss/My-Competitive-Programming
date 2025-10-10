#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = INT_MAX;
// https://acm.timus.ru/problem.aspx?space=1&num=1018
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	if(k >= n or k <= 0) assert(false);
	vector<pair<int, int> > g[n];
	vector<int> sub(n);
	vector< vector<int> > dp(n+10, vector<int>(n+10, -M));
	for(int i = 1;i < n; i++){
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	/*
	7 5
	1 2 20
	2 5 100
	2 3 20
	6 3 70
	4 1 10
	3 7 5
	*/
	function<void(int, int)> dfs=[&](int v, int p){
		dp[v][0] = 0;
		int left = -1, right = -1, LW = -1, RW = -1;
		for(auto [to, w] : g[v]){
			if(to == p) continue;
			if(left == -1){
				left = to, LW = w;
			}else{
				right = to, RW = w;
			}
		}
		if(left != -1) dfs(left, v);
		if(right != -1) dfs(right, v);
		if(left != -1){
			for(int edge = 1; edge < n; edge++){
				dp[v][edge] = max(dp[v][edge], dp[left][edge-1] + LW);
			}
		}
		if(right != -1){
			for(int edge = 1; edge < n; edge++){
				dp[v][edge] = max(dp[v][edge], dp[right][edge-1] + RW);
			}
			for(int edge = 0;edge < n; edge++){
				for(int e = 0; e < edge; e++){
					if(edge-e-1>=0 and e-1>=0)
					dp[v][edge] = max(dp[v][edge], dp[left][e-1] + LW + dp[right][edge-e-1] + RW);
				}
			}
		}
		
	};
	dfs(0, 0);
	if(dp[0][k] < 0) assert(false);
	cout << dp[0][k];
	return 0;
}

