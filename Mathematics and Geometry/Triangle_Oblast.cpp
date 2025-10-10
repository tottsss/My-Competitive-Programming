#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
struct pt{
	int x,y;
};

int area(vector< pt> points){
	vector<pt> A = points;
	A.push_back(A[0]);
	int S = 0, S1 = 0;
	for(int i = 0;i < points.size(); i++){
		S+= (A[i].x * A[i+1].y);
		S1+= (A[i].y * A[i+1].x);	
	}
	return abs(S-S1);
}

long double distance_points(pt a, pt b){
	int s = (a.x - b.x); s*= s;
	int s1 = (b.y-a.y); s1*= s1;
	return (sqrt(s *1.0 + s1) * 1.0);
}

long double get_height(pt centre, pt a, pt b){
	// S = (height*A)/2;
	
	// A = negizi
	// S = area
	long double A = distance_points(a, b);
	long double S = area({centre, a, b}); 
	return (S / A);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	pt a, b, c;
	pt centre;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cin >> centre.x >> centre.y;
	long double H12, H23, H13;
	H12 = get_height(centre, a, b);
	H23 = get_height(centre, b, c);
	H13 = get_height(centre, c, a);
	long double ans = min({H12, H23, H13});
	printf("%.6Lf", ans);
	return 0;
}

