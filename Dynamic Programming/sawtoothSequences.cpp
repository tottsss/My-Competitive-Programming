#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
//https://informatics.msk.ru/mod/statements/view.php?id=2499&chapterid=3002#1
const int mod = 1e9 + 7;
int dp[1001][1001][2];
int n, k;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if(n == 1){
		cout << k;
		return 0;
	}
	int suf = 0;
	for(int i = 1;i <= k; i++){
//		dp[2][i][1]+= dp[2][i-1][1];
		dp[2][i][1] += i-1;
//		dp[2][i][0]+= dp[2][i-1][0];
		dp[2][i][0] += k-i;
		suf = (suf + dp[2][i][1]);
	}
	for(int i = 3;i <= n; i++){
		int pref = 0, suf1 = 0;
		for(int cur = 1; cur <= k; cur++){
			suf-= dp[i-1][cur][1];
			dp[i][cur][1] = (dp[i][cur][1] + pref) % mod;
			dp[i][cur][0] = (dp[i][cur][0] + suf) % mod;
			
//			for(int last = 1; last <= k; last++){
//				if(cur > last){
//					dp[i][cur][1] = (dp[i][cur][1] + dp[i-1][last][0]) % mod;
//				}else if(last > cur){
//					dp[i][cur][0] = (dp[i][cur][0] + dp[i-1][last][1]) % mod;
//				}
//			}
			pref = (pref + dp[i-1][cur][0]);
			suf1 = (suf1 + dp[i][cur][1]);
		}	
		suf = suf1;
	}
	int sum = 0;
	for(int i = 1;i <= k; i++){
		sum = (sum + dp[n][i][0]) % mod;
		sum = (sum + dp[n][i][1]) % mod;
	}
	cout << sum;
	return 0;
}

