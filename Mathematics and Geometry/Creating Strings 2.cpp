#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) (a.begin(), a.end())
 
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
void Cnk(){
	int q; cin >> q;
	vector<int> af(N);
	af[0] = 1;
	for(int i = 1;i <= 1e6; i++){
		af[i] = (af[i - 1] * i) % mod;
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		int result = norm(af[a]);
		result = mul(result, binpow(af[b], mod-2));
		result = mul(result, binpow(af[a-b], mod-2));;
		cout << result%mod << "\n";
	}
}
 
 
main(){
	vector<int> af(N);
	af[0] = 1;
	for(int i = 1;i <= 1e6; i++){
		af[i] = (af[i - 1] * i) % mod;
	}
	string s; cin >> s;
	int n = s.size();
	vector<int> cnt(26, 0);
	for(auto to : s){
		cnt[to-'a']++;
	}
//	for(int i = 0;i < 26; i++){
//		cout << cnt[i] << ' ';
//	}
//	cout << '\n';
	int result = norm(af[n]);
	for(int i = 0; i<26; i++){
		result = mul(result, binpow(af[cnt[i]], mod-2));
	}
	result%= mod;
	cout << result;
	return 0;
}