#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 998244353;

int dp[111][111], dp1[111][111];

//int f(int n, int start, int p){
//	dp[start][0] = 1;
//	for(int i = start;i < n; i++){
//		for(int j = 0;j < n; j++){
//			for(int can = start+1; can<=start+p; can++){
//				dp[can][j+1] = (dp[can][j+1] + dp[i][j]);
//			}
//		}
//	}
//}

int binpow(int a, int n){
	if(n == 0) return 1LL;
	if(n%2==0){
		int b = binpow(a, n/2);
		return (b*b)%mod;
	}else{
		return (a * binpow(a, n-1)) % mod;
	}
}

int norm(int a){
	return ((a%mod)+mod)%mod;
}

int mult(int a, int b){
	return (norm(a) * norm(b)) % mod;
}

int divide(int a, int b){
	return mult(a, binpow(b, mod-2));
}

int inv(int a){
	return binpow(a, mod-2);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, a, b, p, q; cin >> n >> a >> b >> p >> q;
	dp[a][0] = 1;
	for(int i = a;i < n; i++){
		for(int j = 0;j < n; j++){
			for(int can = i+1; can<=i+p; can++){
				dp[min(n, can)][j+1] = (dp[min(n, can)][j+1] + divide(dp[i][j], p)) % mod;
//				dp[min(n, can)][j+1] = divide(dp[min(n, can)][j+1], p); false
			}
		}
	}
	dp1[b][0] = 1;
	for(int i = b;i < n; i++){
		for(int j = 0;j < n; j++){
			for(int can = i+1; can <= i + q; can++){
				dp1[min(n, can)][j+1] = (dp1[min(n, can)][j+1] + divide(dp1[i][j], q)) % mod;
//				dp1[min(n, can)][j+1] = divide(dp1[min(n, can)][j+1], q);false 
			}
		}
	}
	int ans = 0;
	for(int j = 1; j <= n; j++){
		int one = dp[n][j];
		int two = 0;
		for(int aoki = 1; aoki < n; aoki++){
			two = (two + dp1[aoki][j-1]) % mod;
		}
		one = (one * two) % mod;
		ans = (ans + one) % mod;
	}
	cout << ans;
	return 0;
}

