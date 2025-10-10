#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, W; cin >> n >> W;
	int w[n], c[n];
	for(int i = 0;i < n; i++) cin >> w[i];
	for(int i = 0;i < n; i++) cin >> c[i];
	vector< vector<int> > dp(n+1, vector<int>(W+1, 0));
	for(int i = 0;i < n; i++){
		for(int s = 0; s <= W; s++){
			if(i > 0) dp[i][s] = max(dp[i][s], dp[i-1][s]);
			if(s > 0) dp[i][s] = max(dp[i][s], dp[i][s-1]);
			if(s >= w[i]) dp[i][s] = max(dp[i][s], (i > 0 ? dp[i-1][s-w[i]]:  0) + c[i]); 
		}
	}
	vector<int> path;
	int i = n-1, j = W;
	while(i >= 0 and j > 0){
		if(j >= w[i] and dp[i][j] == (i == 0 ? 0 : dp[i-1][j-w[i]]) + c[i]){
			path.push_back(i);
			j-= w[i];
			i--;
		}else if((j == 0 ? INT_MIN : dp[i][j-1]) > (i==0 ? INT_MIN : dp[i-1][j])){
			j--;
		}else i--;
	}
	for(int x : path) cout << x+1 << ' ';
	return 0;
}

