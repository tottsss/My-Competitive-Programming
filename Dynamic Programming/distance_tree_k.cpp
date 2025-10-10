#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 50000;
const int K = 500;

int dp[N+10][K+10];
int n, len, ans;
vector<int> g[N+10];


void dfs(int v, int p){
	dp[v][0] = 1;
	for(int to : g[v]){
		if(to == p) continue;
		dfs(to, v);
		for(int k = 1;k < len; k++){
			ans+= (dp[v][k] * dp[to][len-k-1]);
		}
		for(int k = 0;k < len; k++){
			dp[v][k+1] = (dp[v][k+1] + dp[to][k]);
		}
	}
	ans+= dp[v][len];
}

// CF 161D
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> len;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);

	cout << ans;
	return 0;
}

