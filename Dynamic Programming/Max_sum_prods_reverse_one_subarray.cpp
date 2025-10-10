#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n+1], b[n+1], pref[n+1];
	vector< vector<int> > dp(n+1, vector<int>(n+1,0));
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		cin >> b[i];
	}
	pref[0] = 0, a[0] = 0, b[0] = 0; 
	for(int i = 1;i <= n; i++){
		pref[i] = pref[i-1]+a[i]*b[i];
	}
	int answer = pref[n];
	for(int start = 1;start <= n; start++){
		answer = max(answer, (start-2 >= 0 ? pref[start-2] : 0) + pref[n]-pref[start]+
			a[start-1]*b[start] + b[start-1]*a[start]);
		int l = start, r = start;
		dp[start][start] = a[start]*b[start];
		l--, r++;
		for( ; l >= 1 and r <= n; l--, r++){
			dp[l][r] =  dp[l+1][r-1] + a[l] * b[r] + a[r]*b[l];
			answer = max(answer, dp[l][r] + pref[l-1] + pref[n]-pref[r]);
		}
		l = start, r = start;
		r++;
		for( ; l >= 1 and r <= n; l--, r++){
			dp[l][r] =  dp[l+1][r-1] + a[l] * b[r] + a[r]*b[l];
			answer = max(answer, dp[l][r] + pref[l-1] + pref[n]-pref[r]);
		}
	}
	cout << answer;
	return 0;
}

