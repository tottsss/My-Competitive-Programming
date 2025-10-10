#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9+7;
const int N = 1e6;

int fact[N + 5], inv[N + 5];

int binpow(int a, int n){
	if(n == 0) return 1;
	if(n % 2 == 0){
		int b = binpow(a, n / 2) % mod;
		return (b * b)%mod;
	}else{
		return (a * binpow(a, n-1) % mod) % mod;
	}
	
}

int cnk(int n, int k){
	return( (fact[n] * inv[k]) % mod * inv[n-k]) % mod;
}
void build(){
	fact[0] = inv[0] = 1;
	for(int i = 1;i <= N; i++){
		fact[i] = (fact[i-1] * i) % mod; 
		inv[i] = binpow(fact[i], mod-2) % mod;
	}
}

main(){
   build();
	int q; cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << cnk(a, b) % mod << '\n';
	}
	
	return 0;
}

