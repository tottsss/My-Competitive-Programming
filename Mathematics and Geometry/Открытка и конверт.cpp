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
	int a, b, c, d; cin >> a >> b >> c >> d;
	long double D = (a * a) + (b * b); 
	long double D1 = (c * c) + (d * d);
	
	if((a * b) <= (c * d) and 
	min(c, d)*2 >= min(a,b)  and 
		 D1 >= D){
		cout << "Possible";
	}else if((a * b) <= (c * d) and 
		min(c, d) >= max(a,b)){
		cout << "Possible";
	}
	else cout << "Impossible";
	return 0;
}

