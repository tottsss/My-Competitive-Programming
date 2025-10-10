#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 400;
const int M = 1e15;
int dp[N][N], a[N];
int pref[N];
int n;
 int ans = 0;
 
int f(int l, int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int mn = M;
	for(int k = l; k < r; k++){
		mn = min(mn, f(l, k) + f(k+1, r));
	}
	return dp[l][r] = mn + pref[r]-(l-1>=0 ? pref[l-1] : 0);
} 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
 	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		pref[i] = a[i] + (i>0 ? pref[i-1] : 0);
	}
	memset(dp, -1, sizeof(dp));
	for(int i = 0;i < n; i++){
		dp[i][i] = 0;
	 	if(i+1<n) dp[i][i+1] = a[i]+a[i+1];
	} 
	cout << f(0, n-1);
	return 0;
}