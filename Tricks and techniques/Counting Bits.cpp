#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
 
 
int Find_largest(int n){
	int bit =0 ;
	while((1LL<<bit) <= n){
		bit++;
	}
	return bit-1;
}
 
 
int count_bits(int n){
	if(n <= 1) return n;
	int x = Find_largest(n);
	return (x * (1LL<<(x-1))) + (n - (1LL<<x) + 1) + count_bits(n - (1LL<<x));
}
 
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cout << count_bits(n);
	return 0;
}