#include <bits/stdc++.h>
using namespace std;

#define int long double
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

struct centre{
	int cenX, cenY, len;
};
struct point{
	int x, y;
};
struct line{
	int x, y, x1, y1;
};


bool intersect(line a, line b){
	if(min(b.x1, b.x) <= a.x and max(b.x1, b.x) >= a.x){
		if(min(a.y1, a.y) <= b.y and max(a.y1, a.y) >= b.y) return true;
	}
	return false;
}

int equal(point a, point b){
	if(a.x == b.x and a.y==b.y)return 1;
	return 0;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	centre a, b;
	cin >> a.cenX >> a.cenY >> a.len;
	cin >> b.cenX >> b.cenY >> b.len;
	a.len/= 2;
	b.len/=2;
	line A, B;
	A = {a.cenX, a.cenY+a.len, a.cenX, a.cenY-a.len};
	B = {b.cenX+b.len, b.cenY, b.cenX-b.len, b.cenY};
	if(intersect(A,B)==false){
		cout << 'A';
		return 0;
	}      

	
	
	if(equal({A.x, A.y}, {B.x, B.y}) or equal({A.x, A.y}, {B.x1, B.y1}) or equal({A.x1, A.y1}, {B.x, B.y}) or equal({A.x1, A.y1}, {B.x1, B.y1})){
		cout << 'L';
		return 0;
	}
	
//	if(B.y >= min(A.y, A.y1) and B.y <= max(A.y, A.y1)){
//		cout << 'T';
//		return 0;
//	}
//	if(A.x >= min(B.x, B.x1) and A.x <= max(B.x, B.x1)){
//		cout << 'T';
//		return 0;
//	}
	if((A.y1 == B.y or A.y == B.y) or (A.x == B.x or A.x == B.x1)){
		cout << 'T';
		return 0;
	}

	
	cout << 'X';
	return 0;
}