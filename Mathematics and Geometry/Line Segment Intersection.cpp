#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
 struct pt {
	int x, y;
};
 
const long double EPS = 1E-12;
 
 int det (int a, int b, int c, int d) {
	return (1LL * a * d - b * c);
}
 
 int between (int a, int b, long double c) {
	return min(a,b) <= c + EPS && c <= max(a,b) + EPS;
}
 
 int intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
int intersect (pt a, pt b, pt c, pt d) {
	int A1 = a.y-b.y,  B1 = b.x-a.x,  C1 = -A1*a.x - B1*a.y;
	int A2 = c.y-d.y,  B2 = d.x-c.x,  C2 = -A2*c.x - B2*c.y;
	int zn = det (A1, B1, A2, B2);
	if (zn != 0) {
		long double x = - det (C1, B1, C2, B2) * 1.0 / zn*1.0;
		long double y = - det (A1, C1, A2, C2) * 1.0 / zn*1.0;
		return between (a.x, b.x, x) && between (a.y, b.y, y)
			&& between (c.x, d.x, x) && between (c.y, d.y, y);
	}
	else
		return det (A1, C1, A2, C2) == 0 && det (B1, C1, B2, C2) == 0LL
			&& intersect_1 (a.x, b.x, c.x, d.x)
			&& intersect_1 (a.y, b.y, c.y, d.y);
}
 
 
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int T; cin >> T;
	while(T--){
		pt a, b, c, d;
		cin >> a.x >> a.y >>  b.x >> b.y >> c.x >> c.y;
		cin >> d.x >> d.y;
		if(intersect(a, b, c, d)) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	
	
	return 0;
}