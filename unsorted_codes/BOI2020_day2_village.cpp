#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
const int N = 2e5;

int dp[N];
int n;
vector<int> g[N];
int ans;

void dfs(int v, int par){
	for(int to : g[v]){
		if(to != par) dfs(to, v);
		
	}
	int to = par;
	if(par != v && dp[v] == -1 && dp[to] == -1){
		dp[v] = to, dp[to] = v;
		ans+= 2;
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	for(int i = 0;i <= N; i++) dp[i] = -1;
	cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 1);
	for(int i = 1;i <= n; i++){
		if(dp[i] == -1 or dp[i] == i){
			int to = g[i][0];
			dp[i] = i;
			swap(dp[to], dp[i]);
			ans+= 2;
		}
	}
	cout << ans << '\n';
	for(int i = 1;i <= n; i++) cout << dp[i] << ' ';
	return 0;
}

