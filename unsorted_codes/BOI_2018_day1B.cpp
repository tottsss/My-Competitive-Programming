

#ifndef EVAL
#include "homecoming.h"
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf = 1e17;


ll solve(int n, int k, int a[], int b[]){
	vector< vector<ll> > dp(n, vector<ll>(2, -inf));
	vector<ll> pref(n);
	pref[0] = b[0];
	for(int i = 1;i < n; i++){
		pref[i] = pref[i-1] + b[i];
	}	
	ll ans = 0; 
	dp[0][1] = a[0] - pref[k-1];
	for(int i = 1;i < n; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[i-1][0] + a[i] - (pref[min(n-1, i + k-1)] - pref[i-1]), 
				   dp[i-1][1] + a[i] - (i + k-1 < n ? b[i+k-1] : 0LL));
	}
	ans = max(ans, dp[n-1][0]);
	ans = max(ans, dp[n-1][1]);
	for(int i = 0;i < n; i++) dp[i][0] = dp[i][1] = -inf;
	dp[0][0] = 0;
	for(int i = 1;i < n; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[i-1][0] + a[i] - (pref[min(n-1, i + k-1)] - pref[i-1] + (i + k-1 >= n ? pref[i+k-1-n] : 0LL)), 
					dp[i-1][1] + a[i] - b[(i + k-1) % n]);
	}
	
	
	ans = max(ans, dp[n-1][0]);
	ans = max(ans, dp[n-1][1]);
	return ans;
}
