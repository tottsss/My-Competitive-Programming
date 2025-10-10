#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 100000000;
int dp[115][115][15][15];

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n1, n2, K1, K2; cin >> n1 >> n2 >> K1 >> K2;
//	K1--, K2--;
	dp[0][0][0][0] = 1;
	for(int i = 0; i <= n1; i++){
		for(int j = 0;j <= n2; j++){
			for(int k1 = 0; k1 <= K1; k1++){
				for(int k2 = 0; k2 <= K2; k2++){
			dp[i+1][j][k1+1][0] = (dp[i+1][j][k1+1][0] + dp[i][j][k1][k2])%mod;
			dp[i][j+1][0][k2+1] = (dp[i][j+1][0][k2+1] + dp[i][j][k1][k2])%mod;
				}
			}
		}
	}
	int all = 0;
	for(int i = 0;i <= K1; i++){
		for(int j = 0;j <= K2; j++){
			all = (all + dp[n1][n2][i][j])%mod;
		}
	}
	cout << all;
	return 0;
}

