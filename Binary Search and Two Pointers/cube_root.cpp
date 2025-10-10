#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const long double eps = 0.0000001;
long double a, b, c, d;

long double f(long double x){
	return (a * x*x*x)+ (b*x*x) + (c*x) + d; 
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ifstream cin("cubroot.in");
   ofstream cout("cubroot.out");
   cin >> a >> b >> c >> d;
   long double l = -1e7, r = 1e7;
   cout << fixed << setprecision(6);
   for(int round = 1; round <=100 and r > l; round++){
   		long double mid = 1LL * (l + r) * 0.5;
   		if(f(mid) > 0) l= mid;
   		else r = mid;
   }
   if(fabs(f(r) - 0.0) < eps){
   	cout << r;
   	return 0;
   }
   long double ans= r;
   l = -1e7, r = 1e7;
   for(int round = 1; round <= 100 and r > l; round++){
   		long double mid = 1LL * (l + r) * 0.5;
   		if(f(mid) > 0) r= mid;
   		else l = mid;
   }
   cout << l;
	return 0;
}

