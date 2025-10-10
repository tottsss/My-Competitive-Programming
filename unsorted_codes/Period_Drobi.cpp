#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n; cin >> n;
	vector<int> mp(n, -1);
	int mod = 1, round = 0;
	while(true){
		if(mp[mod] == -1){
			mp[mod] = round;
		}else{
			cout << mp[mod] << ' ' << round - mp[mod];
			return 0;
		}
		round++, mod = (mod*10)%n;
	}

	return 0;
}

