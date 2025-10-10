#include <bits/stdc++.h>
using namespace std;
#define int long long 
main(){
	string a, b;
	cin >> a >> b;
	int dp[a.size() + 1][b.size() + 1];
	int n = a.size();
	int m = b.size();
	memset(dp, -1, sizeof(dp));
	for(int i = 0;i <= m; i++){
		dp[0][i] = i;
	}
	for(int i = 0;i <= n; i++){
		dp[i][0] = i;
	}
	
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			int x = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
			int y = dp[i - 1][j] + 1;
			int z = dp[i][j - 1] + 1;
			dp[i][j] = min(x, min(y, z));
		}
	}
	cout << dp[n][m];
	return 0;
}