#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
	/*
	The number of derangements of 
 numbers, expressed as 
is the number of permutations such that no element appears in its original position. 
Informally, it is the number of ways 
 hats can be returned to 
 people such that no person recieves their own hat.
	*/
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a = 1 % m, b = 0;
	cout << 0 << ' ';
	for(int i = 2;i <= n; i++){
		int c = ((i - 1) *(a + b)%m )% m;
		cout << c << ' ';
		a = b%m, b = c%m;
	}
	
	return 0;
}

