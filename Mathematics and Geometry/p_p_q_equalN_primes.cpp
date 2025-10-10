#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
vector<int> prime;
const int N = 1e7;
int Divs[N+1];
void sieve(){
	for(int i = 2;i <= N; i++){
		if(Divs[i]) continue;
		for(int j = i+i;j <= N; j+= i){
			Divs[j] = 1;
		}
		prime.push_back(i);
	}
}

long long sq(long long x){
	long long SQ = sqrt(x);
	if(SQ*SQ == x) return SQ;
	return -1;
}

void solve(){
	long long n; cin >> n;
	if(n == 1LL) assert(false);
	for(long long q : prime){
		if(n%q!=0)continue;
		long long p = sq(n / q);
		if(p == -1) continue;
		if(p != q and (p * p) * q == n){
			cout << p << " " << q;
			return;
		}
	}
	for(long long p : prime){
		if(n%(p * p) != 0) continue;
		long long q = n / (p * p);
		if(p != q and (p * p) * q == n){
			cout << p << ' ' << q;
			return;
		}
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   sieve();
	int t; cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}

	return 0;
}

