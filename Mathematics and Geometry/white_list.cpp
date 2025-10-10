#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


struct point{
	int x, y;
};


struct rect{
	point A;
	point B;
};


int area(rect a){
	int X = a.B.x - a.A.x;
	int Y = a.B.y - a.A.y;
	if(min(X, Y) < 0LL) return -1LL;
	return X*Y;
}

rect intersect(rect a, rect b){
	point inter, inter1;
	inter.x = max(a.A.x, b.A.x);
	inter.y = max(a.A.y, b.A.y);
	inter1.x = min(a.B.x, b.B.x);
	inter1.y = min(a.B.y, b.B.y);
	return {inter, inter1};
}


int is_intersect(rect a, rect b){
	return area(intersect(a, b))>0;
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	rect white, b1, b2;
	cin >> white.A.x >> white.A.y >> white.B.x >> white.B.y;
	cin >> b1.A.x >> b1.A.y >> b1.B.x >> b1.B.y;
	cin >> b2.A.x >> b2.A.y >> b2.B.x >> b2.B.y;
	int all = area(white);
	rect in1 = {-1,-1, -1, -1}, in2 = {-1, 0, 0, 0};
	int f=0;
	if(is_intersect(white, b1)){
		f++;
		in1 = intersect(white, b1);
		all -= area(in1);
	}
	if(is_intersect(white, b2)){
		f++;
		in2 = intersect(white, b2);
		all -= area(in2);
	}
	
	if(is_intersect(in1, in2) and f == 2){
		all+= area(intersect(in1, in2));
	}
	cout << (all > 0 ? "YES" : "NO");
	return 0;
}

