#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
 
 
int can(string s){
	for(int i = 1;i < s.size(); i++) if(s[i] == s[i-1]) return 0;
	return 1;
}
 
int calc(int a){
	if(a < 0) return 0LL;
	string s = to_string(a);
	int n = s.size();
	reverse(all(s));
	int dp[n+1][10][2];
	memset(dp, 0, sizeof(dp));
	for(int d = 0; d < 10; d++){
		dp[1][d][d > (s[0]-'0')] = 1;
	}	
	for(int i = 2;i <= n; i++){
		for(int d = 0; d < 10; d++){
			for(int last = 0; last < 10; last++){
				if(d == last) continue;
				for(int f : {0, 1}){
					int cur_f = (d > (s[i-1]-'0')) or (d == (s[i-1] - '0') && f);
					dp[i][d][cur_f]+= dp[i-1][last][f];
				}
			}
		}
	}
	int all = 0;
	for(int i = 1;i <= n; i++){
		for(int d = (i != 1); d < 10; d++){
			if(i == n){
				all+= dp[i][d][0];
			}else{
				all+= dp[i][d][0] + dp[i][d][1];
			}
		}
	}
	return all;
}
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;
	cout << calc(b) - calc(a - 1) << '\n';
 
	return 0;
}