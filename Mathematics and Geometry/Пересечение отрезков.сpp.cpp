#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

struct pt{
	int x, y;
};
 
inline int area (pt a, pt b, pt c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d){
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d){
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	pt a, b, c, d;
	cin >> a.x >> a.y >>  b.x >> b.y >> c.x >> c.y;
	cin >> d.x >> d.y;
	if(intersect(a, b, c, d)) cout << "Yes";
	else cout << "No";
			
	
	
	return 0;
}