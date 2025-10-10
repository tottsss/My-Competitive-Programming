#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;
/*

Lets say x times we take 2 from a , and 1 from b
and y times we take 2 from b and 1 from a

meaning:
a = 2x + 1y
b = 1x + 2y

on solving for a and b

2a - b = 3x
2b - a = 3y

x and y should be non negative , and from here we can derive (a+b)%3==0.

*/

void solve(){
	int a, b; cin >> a >> b;
	if(a < b) swap(a, b);
	if(a > 2*b){
		cout << "NO";
		return;
	}
	if((a + b) % 3 == 0){
		cout << "YES";
		return;
	}
	cout << "NO";
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
