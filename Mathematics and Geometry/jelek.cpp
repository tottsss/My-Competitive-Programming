#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int dist(int &a, int &b, int &c, int &d){
	int s = (a-c)*(a-c);
	s+= (b-d) * (b-d);
	return s;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	int a = dist(x, y, x1, y1), b, c;
	long double ans = 0.0;
	for(int x2 = -3000; x2 <= 3000; x2++){
		for(int y2 = -3000; y2 <= 3000; y2++){
			 b = dist(x, y, x2, y2);
			c = dist(x1, y1, x2, y2);
			if(a == max({b, c, a})){
				if(max(b, c) * 9 == min(b, c)*25){
					ans = max(ans, (long double)b*c);
				}	
			}else if(b == max({b, c, a})){
				if(max(a, c) * 9 == min(a, c)*25){
					ans = max(ans, (long double)a*c);
				}
			}else if(c  == max({a, b, c})){
				if(max(b, a) *9 == min(b, a)*25){
					ans = max(ans, (long double)a*b);
				}
			}
		}
	}
	ans = sqrt(ans);
	cout << ceil(ans);
	return 0;
}

