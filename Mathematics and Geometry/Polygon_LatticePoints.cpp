#include <bits/stdc++.h>
using namespace std;


/*
    how many lattice points between two points
     formula gcd(abs(x1 - x2), abs(y1 - y2)) - 1.
*/
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6;

struct pt{
	int x, y;	
};



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector< pt> points(n+1);
	for(int i = 0;i < n; i++){
		cin >> points[i].x >> points[i].y;
	}
	points[n] = points[0];
	int S = 0, S1 = 0, B = 0;
	for(int i = 0;i < n; i++){
		S+= (points[i].x * points[i+1].y);
		S1+= (points[i].y * points[i+1].x);
		pt z = {abs(points[i].x - points[i+1].x), 
			abs(points[i].y - points[i+1].y)};
		B+= __gcd(z.x, z.y);
	}
	int  AREA = abs(S-S1);
	// 2*area = 2*a + b - 2
	// area  = a + (b / 2) - 1
	// area - (b / 2) = a - 1
	
	cout << (AREA-B+2) / 2 << ' ' << B << '\n';
	return 0;
}

