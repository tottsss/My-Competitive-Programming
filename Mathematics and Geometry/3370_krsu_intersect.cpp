#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
struct node{
	int x, y, x1, y1;
};
int area(node a){
	int X = abs(a.x - a.x1) + 1;
	int Y = abs(a.y - a.y1) + 1;
	return X*Y; 
}
int n, sum;
vector<node> p;
int intersect(node a, node b){
	int X = max(a.x, b.x);
	int X1 = min(a.x1, b.x1);
	int Y = max(a.y, b.y);
	int Y1 = min(a.y1, b.y1);
	return ((X1-X)+1) * ((Y1-Y)+1);
}
int is_intersect(node a, node b){
	int X = max(a.x, b.x);
	int X1 = min(a.x1, b.x1);
	int Y = max(a.y, b.y);
	int Y1 = min(a.y1, b.y1);
	if(((X1-X)+1) > 0 and ((Y1-Y)+1) > 0) return 1;
	return 0;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	p.resize(n);
	for(int i = 0;i < n; i++){
		cin >> p[i].x >> p[i].y >> p[i].x1 >> p[i].y1;
		sum+= area(p[i]);
	}
	for(int i = 0;i < n; i++){
		if(is_intersect(p[i], p[i-1])) sum-= intersect(p[i], p[i-1]);
	}
	cout << sum;
	return 0;
}

