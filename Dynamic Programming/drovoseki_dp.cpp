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
	vector<int> x(n + 1, 0), h(n + 1, 0);
	for(int i = 0;i < n; i++){
		cin >> x[i] >> h[i];
	}	
	vector<vector<int> > dp(n+1, vector<int>(2,0));
	// dp[prefix][0] = [x[i] - h[i], x[i]]
	// dp[prefix][1] = [x[i], x[i] + h[i]]
	dp[0][0] = 1;
	if(x[0] + h[0] < x[1]) dp[0][1] = 1;
	x[n] = (int)1e18;
	for(int i = 1;i < n; i++){
		if(x[i]-h[i] > x[i-1]){
			dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
		}else dp[i][0] = max(dp[i][0], dp[i-1][0]);
		if(x[i]-h[i] > x[i-1] + h[i-1]){
			dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
		}else{
			dp[i][0] = max(dp[i][0], dp[i-1][1]);
		}
		if(x[i] + h[i] < x[i+1]){
			dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][1]) + 1);
		}else dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][1]));
	}
	cout << max(dp[n-1][0], dp[n-1][1]);
	return 0;
}