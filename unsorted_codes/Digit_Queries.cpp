#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int tens(int c){
	int t = 1LL;
	while(c--) t*= 10LL;
	return t;
}
int calc(int m){
	int sum = 0;
	for(int base = 18; base >= 0; base--){
		int ten = tens(base);
		if(ten > m) continue;
		sum+= (m - ten + 1) * (base + 1);
		m = ten-1;
	}
	return sum;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while(q--){
		int pos; cin >> pos;
		int l = 0, r = 1e18;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(calc(mid) < pos) l = mid;
			else r = mid;
		}
		pos-= calc(l);
		l++;
		cout << to_string(l)[pos-1] << '\n';
	}

	return 0;
}

