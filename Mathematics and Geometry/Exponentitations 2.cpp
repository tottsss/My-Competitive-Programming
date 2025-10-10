#include "bits/stdc++.h"
using namespace std;
 #define int long long
 const int N = 1e6+1;
 
main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	int M = 1e9+7;
	while(t--){
		int x, y , z; cin >> x >> y >> z;
		function<int(int, int, int)> binpow=[&](int a, int b, int mod){
			if(b == 0) return 1LL;
			if(b%2 == 1){
				int B = binpow(a, b-1, mod);
				return (B*a*1LL)%mod;
			}else{
				int B = binpow(a, b / 2, mod)%mod;
				return (B*B*1LL)%mod;
			}
		};
		int pow1 = binpow(y, z, M-1) % (M-1);
		cout << binpow(x, pow1, M)%M << '\n';
	}
	return 0;
}