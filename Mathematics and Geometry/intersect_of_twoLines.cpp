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
  	int A1, B1, C1, A2, B2, C2 ; cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;
  	long double fx = -C1 * B2 + C2 * B1;
  	fx = fx / (long double)(A1 * B2 - B1 * A2);
  	long double fy = -A1 * C2 + A2 * C1;
  	fy = fy / (long double)(A1 * B2 - B1 * A2);
  	cout << fixed << setprecision(6);
  	cout << fx << ' ' << fy;
	return 0;
}

