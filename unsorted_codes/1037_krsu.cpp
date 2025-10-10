#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int a, b, c, d, mod;


int isprime(int n){
	if(n==1) return 0;
	for(int i =  2;i * i <= n; i++){
		if(n%i==0)return 0;
	}
	return 1;
}

void factorization(int n, map<int, int>&cnt){
	for(int i = 2;i * i <= n; i++){
		if(isprime(i)==0) continue;
		while(n>1 and n%i==0){
			n/= i;
			cnt[i]++;
		}
	}
	if(n > 1) cnt[n]++;
}

void power_fc(map<int, int>&cnt, int PW){
	for(auto &c : cnt){
		c.ss*= PW;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> a >> b >> c >> d >> mod;
	map<int, int> PA, PB;
	factorization(a, PA);
	factorization(c, PB);
	power_fc(PA, b);
	power_fc(PB, d);
	vector<pair<int, int> > GCD;
	for(auto c : PA){
//		cout << c.ff << ' ' << c.ss << '\n';
		int MN = c.ss, k = 0;
		for(auto c1 : PB){
			if(c1.ff == c.ff){
				k = 1;
				MN = min(MN, c1.ss);
			}
		}
		if(k){
			GCD.push_back({c.ff,MN});
		}
	}	
	int S = 1;
	for(auto c : GCD){
		for(int i = 1;i <= c.ss; i++){
			S = (S * c.ff)%mod;
		}
	}
	cout << S%mod;
	return 0;
}

