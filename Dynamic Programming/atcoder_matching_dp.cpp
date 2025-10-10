#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;

int dp[1<<21];
int a[21][21];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1 and i == 0){
				dp[(1<<j)] = 1;
			}
		}
	}
	for(int mask = 0; mask < (1<<n); mask++){
		int man = __builtin_popcount(mask);
		if(man <= 1) continue;
		man--;
		for(int j = 0;j < n; j++){
			if(!(mask&(1<<j)) or !a[man][j]) continue;
			dp[mask] =(dp[mask] +  dp[mask^(1<<j)]) % mod;
		}
	}
	cout << dp[(1<<n)-1];
	return 0;
}

