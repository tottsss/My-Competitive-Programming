#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e6 + 2;
int binpow(int a, int n){
	if(n == 0) return 1;
	else if(n % 2 == 1){
		return ((binpow(a, n - 1)%mod*a) % mod);
	}else{
		int b = binpow(a, n / 2); b%= mod;
		return ((b*b)%mod);
	}
}
int norm(int a){
	return (((a % mod) +mod)%mod);
}
 
int mul(int a, int b){
	return ((norm(a) * norm(b)) % mod);
}
void catalan(){
	int n; cin >> n;
	if(n % 2 == 1){
		cout << 0;
		return;
	}
	n/= 2;
	vector<int> af(N);
	af[0] = 1;
	for(int i = 1;i <= 1e6; i++){
		af[i] = (af[i - 1] * i) % mod;
	}
	int result = norm(af[2*n]);
	result = mul(result, binpow(af[n], mod-2));
	result = mul(result,  binpow(af[n], mod-2));;
	result = mul(result,  binpow(n + 1, mod-2));
	cout << result%mod << "\n";
} 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	catalan();
 
	return 0;
}