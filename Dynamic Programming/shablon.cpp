#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	a = '#' + a;
	b = '#' + b;
	int n = a.size();
	int m = b.size();
	vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
	dp[0][0] = 1;
	for(int i = 1;i < n; i++){
		if(a[i] != '*') break;
		dp[i][0] = 1;
	}
	for(int j = 1;j < m; j++){
		if(b[j] != '*') break;
		dp[0][j] = 1;
	}
	for(int i = 1;i < n; i++){
		for(int j = 1;j < m; j++){
			if(a[i]>='A' and a[i] <= 'Z'){
				if(b[j]>='A' and b[j]<= 'Z'){
					if(a[i] == b[j] and dp[i-1][j-1]){
						dp[i][j] = 1;
					}
				}else if(b[j] == '?'){
					if(dp[i-1][j-1]) dp[i][j] = 1;
				}else{
					for(int k = 0;k <= i; k++){
						if(dp[k][j-1]){
							dp[i][j] = 1;
							break;
						}
					}
				}
			}else if(b[j]>='A' and b[j]<= 'Z'){
				if(a[i] == '?'){
					if(dp[i-1][j-1]) dp[i][j] = 1;
				}else{
					for(int k = 0;k <= j; k++){
						if(dp[i-1][k]){
							dp[i][j] = 1;
							break;
						}
					}
				}
			}else if(a[i] == '*' or b[j] == '*'){
				int ok = 0;
				for(int k = 0;k <= j; k++){
					if(dp[i-1][k]){
						ok = 1;
						break;
					}
				}
				for(int k = 0;k <= i; k++){
					if(dp[k][j-1]){
						ok = 1;
						break;
					}
				}
				dp[i][j] = ok;
			}else if(a[i] == '?' and b[j] == '?'){
				if(dp[i-1][j-1]) dp[i][j] = 1;
			}else assert(false);
		}
	}
	cout << (dp[n-1][m-1] ? "YES" : "NO");
	return 0;
}

