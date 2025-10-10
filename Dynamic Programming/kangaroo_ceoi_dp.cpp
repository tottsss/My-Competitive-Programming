#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;


void add_self(int &a, int b){
	a+= b;
	if(a < 0) a+= mod;
	if(a >= mod) a-= mod;
}

int mul(int a, int b){
	return (a * b) % mod;
}
int dp[2100][2100];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	dp[1][1] = 1;
	for(int i = 2;i <= n; i++){
		for(int j = 1;j <= n; j++){
			if(i == a || b == i){
				add_self(dp[i][j], dp[i-1][j-1]);
				add_self(dp[i][j], dp[i-1][j]);
			}else{
				add_self(dp[i][j], mul(dp[i-1][j+1], j));
				add_self(dp[i][j], mul(dp[i-1][j-1], j - (i > a) - (i > b)));
			}
		}
	}
	cout << dp[n][1];
	return 0;
}

