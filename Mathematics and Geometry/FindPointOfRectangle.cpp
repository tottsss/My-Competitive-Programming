#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;


struct pt{
	int x, y;	
};

pt operator +(const pt& left, const pt& right){
	return {left.x + right.x, left.y + right.y};
}

pt operator -(const pt& left, const pt& right){
	return {left.x - right.x, left.y - right.y};
}

int distance(pt a, pt b){
	int s = (a.x - b.x); s*= s;
	int s1 = (a.y - b.y); s1*= s1;
	return (s+s1);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	pt a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	pt d;
	if(distance(a, c) == distance(a, b) + distance(c,  b)){
		// a and c are hypot
		d = a + c - b;
	}else if(distance(a, b) == distance(a, c) + distance(c, b)){
		// a and b are hypot
		d = a + b - c;
	}else{
		// b and c are hypot
		d = b + c - a;
	}

	cout << d.x << ' ' << d.y;
	return 0;
}

