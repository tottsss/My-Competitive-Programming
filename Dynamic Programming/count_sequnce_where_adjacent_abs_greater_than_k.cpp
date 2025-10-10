#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 998244353;
int dp[1001][5001];
int n, m, k;

int sub(int a, int b){
	return (((a-b)%M)+M)%M;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m; i++){
		dp[1][i] = 1;
	}
	for(int i = 2;i <= n; i++){
		int sum = 0, all = 0;
		for(int j = 1;j <= m; j++){
			all = (dp[i-1][j] + all) % M;
		}
		for(int j = max(1, 1-k+1); j <= min(1+k-1, m); j++){
			sum = (sum + dp[i-1][j]) % M;
		}
		for(int j = 1;j <= m; j++){
			dp[i][j] = sub(all, sum);
			if(j-k+1 > 0) sum = sub(sum, dp[i-1][j-k+1]);
			if(j+k <= m) sum = (sum + dp[i-1][j+k])%M;

			// naive solution
//			for(int c = 1; c <= j-k; c++){
//				dp[i][j] = (dp[i][j] + dp[i-1][c]) % M;
//			}
//			for(int c = j+k; c <= m; c++){
//				dp[i][j] = (dp[i][j] + dp[i-1][c]) % M;
//			}
			
		}
		
	}
	int ans = 0;
	for(int i = 1;i <= m; i++){
		ans = (ans + dp[n][i])%M;
	}
	cout << ans;
	return 0;
}

