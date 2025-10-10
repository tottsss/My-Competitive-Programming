#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long long
const int mod = 1e17;
const int N = 3000;
int a[N+5], pref[N+5], n, k;
int dp[N+5][N+5];
 
 
int cost(int l, int r){
	int s = pref[r] - pref[l-1];
		return s * s;
}
 
 
void rec(int com, int l, int r, int optl, int optr){
	if(l > r) return;
	int mid = (l + r)>>1;
	int optmid = -1, mn = mod;
	for(int j = optl; j <= min(optr,mid); j++){
		int ss = cost(j, mid);
		if(mn >= ss + dp[com-1][j-1]){
			optmid = j;
			mn = ss + dp[com-1][j-1];
		}
	}
	dp[com][mid] = mn;
	rec(com, l, mid-1, optl, optmid);
	rec(com, mid+1, r, optmid, optr);
}
 
 
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 0;i <= n; i++){
		for(int j = 0;j <= n; j++) dp[i][j] = mod;
	}
	dp[0][0] = 0;
	for(int i = 1;i <= n; i++){
		pref[i] = pref[i-1] + a[i]; 
	}
	
	for(int com = 1; com <= k; com++){
		
		rec(com, 1, n, 1, n);
	}
	
	cout << dp[k][n];
	return 0;
}	