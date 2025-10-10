#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e18;

int sz(int x){
	if(x==0) return 1;
	int s = 0;
	while(x > 0) x/= 10, s++;
	return s; 
}


int good(int m){
	if(m < 0) return 0;
	int pref = 0, sz = 0, add = 1;
	for(int i = 9; ;i = (i * 10) + 9, add++){
		if(m >= i){
			sz+= (i-pref)*add;
		}else{
			sz+= (m-pref)*add;
			return sz+1;
		}
		pref = i;
	}
	return sz+1;
}

/*
987906543456789
assertation
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int s; cin >> s;
	if(s == 1){
		cout << "1\n" << "0 0";
		return 0;
	}
	
	for(int left = 0; left <= 1e5; left++){
		int l = 0, r = 2e18;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			if(good(mid) - good(left-1) >= s) r = mid;
			else l = mid;
		}
		int need = (good(r) - good(left-1)) - s;
		if(r > M or need < 0) continue;
		l = left;
		// commentke alyngan kodtty koshso da chygat
//		while(need >= sz(r)){
//			need-= sz(r);
//			r--;
//		}
//		while(need >= sz(l)){
//			need-= sz(l);
//			l++;
//		}
		if(need == 0){
			cout <<r-l+1 << '\n';
			cout << l << ' ' << r << '\n';
			return 0;
		}
	}
	cout << -1;
	return 0;
}

