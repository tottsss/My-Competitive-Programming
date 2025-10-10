#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
/*
Given a natural number N. 
Represent it as a sum of simple natural 
numbers so that the product of these terms is maximal.

*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a = 0, b = 0;
	if(n%3==0){
		b = n / 3;
	}else if(n%3==1){
		a = 2;
		b = (n-4) / 3;
	}else if(n%3==2){
		a = 1;
		b = (n-2) / 3;
	}
	if(a > 0) cout << 2 << ' ' << a << ' ';
	if(b > 0) cout << 3 << ' ' << b << " ";
	return 0;
}

