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
	int A = d-b;
	int B = a-c;
	cout << A << ' ' << B << " ";
	cout << -1 * (A*a + B*b);
	return 0;
}

   