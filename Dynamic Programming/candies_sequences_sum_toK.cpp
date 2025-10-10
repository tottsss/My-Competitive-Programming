#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
const int S = 1e5;
const int N = 100;
const int mod = 1e9 + 7;
int dp[N+5][S+5];
int pref[S+5];

int get(int l, int r){
	if(l>r) swap(l, r);
//	return (pref[r]-(l-1>=0 ? pref[l-1] : 0));
	return (((pref[r]-(l-1>=0 ? pref[l-1] : 0) ) %mod)+mod)%mod;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i <= k; i++){
		if(i <= a[0]) dp[0][i]++;
		pref[i] = (i>0 ? pref[i-1] : 0) + dp[0][i];
	}
	for(int i = 1;i < n; i++){
		for(int W = k; W >= 0; W--){
			dp[i][W] = (dp[i][W] + get(W, W-a[i])) % mod; 	
		}
		for(int W = 0;W <= k; W++){
			pref[W] = ((W > 0 ? pref[W-1] : 0) + dp[i][W])%mod;
		}
	}
	cout << dp[n-1][k];
	return 0;
}

