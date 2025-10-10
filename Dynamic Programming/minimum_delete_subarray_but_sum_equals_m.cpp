#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int dp[n+1][3001][2];
	for(int i = 0;i < n; i++){
		for(int j = 0;j <= m; j++){
			dp[i][j][0] = mod;
			dp[i][j][1] = mod;
		}
	}
	dp[0][0][0] = 1;
	dp[0][a[0]][1] = 0;
	for(int i = 1;i < n; i++){
		for(int j = 0;j <= m; j++){
			if(j + a[i] <= m) dp[i][j+a[i]][1] = min(dp[i][j+a[i]][1], min(dp[i-1][j][0], dp[i-1][j][1]));
			dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + 1);
		}
	}
	for(int j = 1;j <= m; j++){
		int k = min(dp[n-1][j][0], dp[n-1][j][1]);
		if(k >= mod) k = -1;
		cout << k << '\n';	
	}
	return 0;
}

