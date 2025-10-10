/*
You are given an array A of n elements. 
Also you are given another array B of m elements. 
Any subset (i1, i2, i3, ..., ip) is bad if equals any value of B.
Now your job is to find the number of good subsets. Empty Subset has XOR value of 0.
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
int dp[1025][1025];
int b[1025], a[1025];
void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	memset(b, 0, sizeof(b));
	for(int i = 1;i <= m; i++){
		int x; cin >> x;
		b[x] = 1;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1;i <= n; i++){
		for(int xr = 0; xr < 1024; xr++){
			dp[i][xr] = (dp[i-1][xr] + dp[i-1][xr ^ a[i]]) % mod;
		}
	}
	int sum = 0;
	for(int xr = 0; xr < 1024; xr++){
		if(!b[xr]) sum = (sum + dp[n][xr]) % mod;
	}
	cout << sum << '\n';
}
 
 
main(){
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cout << "Case " << t << ": ";
		solve();
	}
	
	return 0;
} 