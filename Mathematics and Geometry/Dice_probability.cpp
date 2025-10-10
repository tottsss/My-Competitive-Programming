#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	if(n > b or n*6 < a){
		cout << "0.000000";
		return 0;
	}
	vector< vector<long double> > dp(n+1, vector<long double>(b+1, 0));
	dp[0][0] = 1;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= b; j++){
			for(int k = 1;k <= j && k <= 6; k++){
				dp[i][j] =(dp[i][j] +  dp[i-1][j-k]);
			}
		}
	}
	long double ans = 0.0;
	for(int i = a;i <= b; i++){
		ans+= dp[n][i];
	}
	for(int i = 1;i <= n; i++){
		ans = ans / 6.0;
	}
	cout << fixed << setprecision(6);
	cout << ans;
	return 0;
}

