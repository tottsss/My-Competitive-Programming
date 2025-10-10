#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;
const int mod = 1e9 + 7;
int dp[N+1][2];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   dp[1][1] = 1, dp[1][0] = 1;
	for(int i = 2;i <= N; i++){
		dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
		dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
		dp[i][1] = (dp[i][1] + dp[i-1][1]*4) % mod;
		dp[i][0] = (dp[i][0] + dp[i-1][0]*2) % mod;
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << (dp[n][0] + dp[n][1]) % mod << '\n';
	}
	
	
	return 0;
}

