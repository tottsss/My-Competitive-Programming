#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int n;
map<pair<int, int>, int> mp;
int f(int a, int b){
	if(a > b) swap(a, b);
	if(a == 0 && b == 0) return 0;
	if(mp.count({a, b})) return mp[{a, b}];
	int win = 0;
	for(int k = 1; k <= a / 2; k++){
		if(!f(a - k, b)){
			win = 1;
			break;
		}
	}
	for(int k = 1;k <= b / 2; k++){
		if(!f(a, b - k)){
			win = 1;
			break;
		}
	}
	mp[{a, b}] = win;
	return win;
}


main(){
   int t; cin >> t;
   while(t--){
		int n; cin >> n;
		
		for(int a = 1; a <= n / 2; a++){
			int b = n - a;
			if(!f(a, b)){
				cout << a << ' ' << b << " = " << '\n';
			}
		}
	}
	return 0;
}

