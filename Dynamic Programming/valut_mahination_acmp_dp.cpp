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
	int n; cin >> n;
	 vector<pair<long double, long double> > a(n + 1);
	for(int i = 1;i <= n; i++){
		cin >> a[i].ff >> a[i].ss;
	}
	vector<long double> rus(n + 1), dol(n + 1), eur(n + 1);
	rus[0] = 100.0;
	dol[0] = 0.0;
	eur[0] = 0.0;
	for(int i = 1;i <= n; i++){
		rus[i] = max({rus[i-1], dol[i-1] * a[i].ff, eur[i-1] * a[i].ss});
		dol[i] = max({dol[i-1], rus[i] / a[i].ff});
		eur[i] = max({eur[i-1], rus[i] / a[i].ss});
	}
	
	
	cout << fixed << setprecision(2);
	cout << rus[n];
	return 0;
}

