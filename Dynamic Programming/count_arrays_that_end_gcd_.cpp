#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
int binpow(int a, int n){
	if(n == 0) return 1;
	if(n%2==0){
		int b = binpow(a, n / 2);
		return (b * b) % mod;
	}else{
		return (a * binpow(a, n-1)) % mod;
	}
}

void add_self(int &a, int b){
	a+= b;
	if(a < 0) a+= mod;
	if(a >= mod) a-= mod;
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> dp(k+1, 0);	
	for(int i = k;i >= 1; i--){
		int ans = binpow(k / i, n);
		for(int j = i+i; j <= k; j+= i){
			add_self(ans, -dp[j]);
		}
		dp[i] = ans;
	}
	int sum = 0;
	for(int i = 1;i <= k; i++){
//		cout << i << " = " << dp[i] << '\n';
		add_self(sum, (i * dp[i]) % mod);
	}
	cout << sum;
	return 0;
}

