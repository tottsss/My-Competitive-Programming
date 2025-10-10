#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n + 1];
	vector< vector<int> > dp(1234, vector<int>(1234, INT_MAX));
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a+n+1);
	for(int i = 1;i <= n; i++){
		dp[i][i] = a[i];
		if(i + 1 <= n){
			dp[i][i+1] = a[i+1]-a[i];
		}
	}
	for(int len = 3; len <= n; len++){
		for(int i = 1;i + len -1 <= n; i++){
			int j = i+len-1;
			dp[i][j] = a[j]-a[i];
			for(int k = i + 1;k < j -1; k++){
				dp[i][j] = min(dp[i][j], max(dp[i][k],  dp[k + 1][j]));
			}
		}
	}
	cout << dp[1][n];
	return 0;
}

