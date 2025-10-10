#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;


int dp[1<<10][2];

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	dp[0][0] = 1;
	// mask... i-th bit is 0 than its covered
	for(int round = 0; round < m; round++){
		for(int i = 0;i < n; i++){
			for(int mask = 0; mask < (1<<n); mask++){
				dp[mask][1] = dp[mask^(1<<i)][0];
				if(i == 0) continue;
				if(mask & (1<<i)) continue;
				if(mask & (1<<(i-1))) continue;
				dp[mask][1]+= dp[mask ^ (1<<(i-1))][0];
				if(dp[mask][1] >= mod) dp[mask][1] -= mod;
		
			}
			for(int mask = 0; mask < (1<<n); mask++) dp[mask][0] = dp[mask][1];
		}
	}
	cout << dp[0][0] % mod;
	return 0;
}