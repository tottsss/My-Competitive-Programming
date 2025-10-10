#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long

const long double EPS = 0.000000001;
int dist(int a, int b, int c, int d){
	return (a-c) * (a-c) + (b-d)*(b-d);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ifstream cin("point3.in");
   ofstream cout("point3.out");
	int px, py; cin >> px >> py;
	int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
	long double len = 1.0 * sqrt(dist(px, py, x1, y1)) +  1.0 * sqrt(dist(px, py, x, y));
	long double len1 = sqrt(dist(x, y, x1, y1) * 1.0);
	if(fabs(len-len1) < EPS){
		cout << "YES";
	}else cout << "NO";
	return 0;
}

