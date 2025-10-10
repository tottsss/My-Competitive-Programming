#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int mod ; cin >> mod;
	int  number = 0;
	for(auto ch : s){
		number = (number*10 + (ch - '0'))%mod;
	}
	cout << number%mod;
	return 0;
}

