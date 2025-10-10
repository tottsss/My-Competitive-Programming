#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


void umin(int &need, int m){
	if(need == -1 or need > m) need = m;
}


void solve(){
	int W, H, x, y, x1, y1, w, h;
	cin >> W >> H >> x >> y >> x1 >> y1 >> w >> h;
   	int ok = 1, need = -1;
   	if(x1-x + w <= W){
   		ok = 0;
   		umin(need, max(0LL, w-x));
   		umin(need, max(0LL, x1 - (W-w)));
	}
   	if(y1-y + h <= H){
   		ok = 0;	
		umin(need, max(0LL, h - y));
		umin(need, max(0LL, y1 - (H-h)));
	}
   	if(ok == 1){
   		cout << -1;
		return;	
	}
   	cout << fixed << setprecision(6);
   	cout << (long double)need;
}


main(){
   	int test; cin >> test;
   	while(test--){
   		solve();
   		cout << '\n';
	}
	return 0;
}

