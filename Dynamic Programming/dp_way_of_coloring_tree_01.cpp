#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9+7;
const int N = 1e5;
int dp[N+10][2];
int n;
vector<int> g[N+5];

void dfs(int v, int p){
	int white = 1, black = 1;
	for(int to : g[v]){
		if(to == p) continue;
		dfs(to, v);
		white =(white * (dp[to][0] + dp[to][1])) % mod;
		black = (black * dp[to][0])%mod;
	}
	dp[v][0] = white, dp[v][1] = black;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, -1);
	cout << (dp[1][0] + dp[1][1]) % mod;
	return 0;
}

