#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5000;
int inf = -1e9;
int n, m, k;
int a[N+1], dp[N+1][N+1], pref[N+1];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
	}
	// https://codeforces.com/contest/467/problem/C
	int answer = 0;
	for(int i = 1;i <= k; i++){
		for(int j = 1;j <= n; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
		for(int j = m;j <= n; j++){	
			dp[i][j] = max(dp[i][j], dp[i-1][j-m] + pref[j]-pref[j-m]);
		}
		for(int j = 1;j <= n; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}
	for(int i = 1;i <= n; i++){
		answer = max(answer, dp[k][i]);
	}
	cout << answer;
	return 0;
}