#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n+1];
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	vector< vector<int> > dp(n + 10, vector<int>(2, 0));
	dp[2][1] = a[2];
	dp[2][0] = a[1];
	for(int i = 3;i <= n; i++){
		if(i&1){
			dp[i][1] = a[i] + max({dp[i-2][0], dp[i-2][1], dp[i-3][0], dp[i-3][1]});
			dp[i][0] = max({a[i-1] + dp[i-2][0], a[i-1] + dp[i-3][1], a[i-1] + dp[i-3][0], a[i-2] + dp[i-3][0]});
		}else{
			dp[i][1] = a[i] + max({dp[i-2][1], dp[i-2][0], dp[i-1][0]});
			dp[i][0] = a[i-1] + dp[i-2][0];
		}
	}
	
	cout << max(dp[n][0], dp[n][1]);
	return 0;
}

