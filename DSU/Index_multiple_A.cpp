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
	int n, m; cin >> n>> m;
	vector< vector<int> > dp(2022, vector<int>(2022, -(1LL<<60)));
	vector<int> a(n+1) ,pref_max(n + 1, -(1LL<<60));
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		pref_max[i] = max(pref_max[i-1], a[i]);
	}
	dp[1][1] = a[1];
	for(int i = 2;i <= n; i++){
		for(int len = 1; len <= m and len <= i; len++){
			if(len == 1){
				dp[i][len] = pref_max[i];
			}else{
				dp[i][len] = max(dp[i][len], dp[i-1][len-1] + (len * a[i]));
				dp[i][len] = max(dp[i][len], dp[i-1][len]);
			}
		}
	}
	
	cout << dp[n][m];
	return 0;
}

