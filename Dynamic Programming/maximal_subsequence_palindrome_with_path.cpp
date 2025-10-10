#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector< vector<int> > dp(n+10, vector<int>(n+10,0));
	map< pair<int, int>, vector<int> > mp;
	int mx = 1;
	for(int i = 0;i < n; i++){
		dp[i][i] = 1;
		mp[{i,i}].push_back(i);
	} 
	for(int len = 2;len <= n; len++){
		for(int i = 0; i + len-1 < n; i++){
			int j = i + len-1;
			if(dp[i][j-1] > dp[i][j]){
				dp[i][j] = dp[i][j-1];
				mp[{i, j}] = mp[{i, j-1}];
			}
			if(dp[i+1][j] > dp[i][j]){
				dp[i][j] = dp[i+1][j];
				mp[{i, j}] = mp[{i+1, j}];
			}
			for(int k = i+1; k <= j; k++){
				if(s[i] == s[k]){
					if(dp[i+1][k-1]+2 > dp[i][j]){
						dp[i][j] = dp[i+1][k-1]+2;
						mp[{i, j}] = mp[{i+1, k-1}];
						mp[{i,j}].push_back(i);
						mp[{i,j}].push_back(j);
					}
				}
			}
		}
	}
	cout << dp[0][n-1] << '\n';
	set<int> st;
	for(int x : mp[{0, n-1}]){
		st.insert(x);	
	}
	for(int i = 0;i < n; i++) if(st.count(i)) cout << s[i];
	return 0;
}

