#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int isPair(char a, char b){
	return (a==b);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector< vector<int> > dp(n+10, vector<int>(n+10,0));
	int mx = 1;
	for(int i = 0;i < n; i++) dp[i][i] = 1;
	for(int len = 2;len <= n; len++){
		for(int i = 0; i + len-1 < n; i++){
			int j = i + len-1;
			dp[i][j] = max(dp[i][j-1], dp[i][j]);
			dp[i][j] = max(dp[i+1][j], dp[i][j]);
			for(int k = i+1; k <= j; k++){
				if(s[i] == s[k]){
					dp[i][j] = max(dp[i+1][k-1]+2, dp[i][j]);
				}
			}
			mx = max(dp[i][j],  mx);
		}
	}
	cout << mx;
	return 0;
}

