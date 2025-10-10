#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;


void solve(){
	string s; cin >> s;
	s = '#' + s;
	string a = s;
	int n = s.size();
	vector< vector<int> > dp(n + 1, vector<int>(n + 1, 2));
	
	for(int i = 1;i < n; i++){
		if(s[i] == s[i+1]) dp[i][i+1] = 1;
		else dp[i][i+1] = 2;
	}

	for(int len = 4; len <= n; len+= 2){
		for(int i = 1;i + len-1 <= n; i++){
			int j = i + len - 1;
			int s = 0, s1 = 0;
			if(dp[i + 1][j-1] == 2) s = 2;
			if(dp[i+1][j-1] == 1 and a[i] != a[j]) s = 2;
			
			if(dp[i+2][j] == 2) s1 = 2;
			if(dp[i+2][j] == 1 and a[i] > a[i+1]) s1 = 2;
			if(s == 2 and s1 == 2){
				dp[i][j] = 2;
				continue;
			}	
			if(dp[i][j-2] == 2) s1 = 2;
			if(dp[i][j-2] == 1 and a[j] > a[j-1]) s1 = 2;
			if(s == 2 and s1 == 2){
				dp[i][j] = 2;
				continue;
			}
			s = 0, s1 =0;
			if(dp[i+1][j-1] == 1 and a[i] == a[j]){
				s = 1;
			}
			if(dp[i+2][j] == 1 and a[i] == a[i+1]) s1 = 1;
			if(s == 1 and s1 == 1){
				dp[i][j] = 1;
				continue;
			}
			if(dp[i][j-2] == 1 and a[j] == a[j-1]){
				s1 = 1;
			}
			if(s == 1 and s1 == 1){
				dp[i][j] = 1;
				continue;
			}
			
			
			dp[i][j] = 0;
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j = i;j <= n; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	if(dp[1][n] == 2) cout << "Alice";
	else if(dp[1][n] == 0) cout << "Bob";
	else cout << "Draw";
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
