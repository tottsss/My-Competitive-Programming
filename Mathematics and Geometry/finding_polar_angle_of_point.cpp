#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ifstream cin("angle1.in");
   ofstream cout("angle1.out");
	long long x, y; cin >> x >> y;
	cout << fixed << setprecision(6);
	long double ans = atan2(y, x);
	if(y < 0){
		ans = ans + 2.0 * 3.1415926535;
	}
	cout << ans;
	return 0;
}

