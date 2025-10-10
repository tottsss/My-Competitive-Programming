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
   ifstream cin("length.in");
   ofstream cout("length.out");
	int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
	long double len = sqrt((x-x1)*(x-x1) + (y-y1) * (y-y1));
	cout << fixed << setprecision(6);
	cout << len;
	return 0;
}

