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
	int px, py; 
	int x, y, x1, y1;
	cin >> px >> py >> x >> y >> x1 >> y1;
	int A = y-y1, B = x1-x, C = -1 * (A*x + B*y);
	int nx = A, ny = B;
	long double nlen =(long double)sqrt(A*A + B*B);
	long double all = 1.0 * A*px + (long double)B*py + (long double)C;
	cout << fixed << setprecision(6);
	cout << fabs((long double)all / nlen);
	return 0;
}

