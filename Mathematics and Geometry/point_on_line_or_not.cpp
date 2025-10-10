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
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	if(a*x + b*y + c == 0) cout << "YES";
	else cout << "NO";
	return 0;
}

   