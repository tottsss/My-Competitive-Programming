#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

__int128 binpow(int a, int n){
	if(n == 0) return 1;
	if(n%2==0){
		__int128 b =binpow(a, n / 2);
		return b*b;
	}else{
		return binpow(a, n-1) * a;
	}
}
int n;
__int128 toBase(int mask, int base){
	__int128 s = 0;
	for(int i = 0;i < 8; i++){
		if(mask & (1<<i)){
			s+= binpow(base, i);
			if(s > n) return n+1;
		}
	}
	return s;

}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int t; cin >> t;
	set<int> ans;
	while(t--){
		cin >> n;
		for(int base = 2; base <= 1000; base++){
			int x = n, ok = 1;
			while(x > 0){
				if(x%base > 1){
					ok = 0;
					break;
				}
				x/= base;
			}
			if(ok) ans.insert(base);
		}
		for(int mask = 0; mask < (1<<8); mask++){
			int l = 1, r = (int)1e18 + 10;
			while(l + 1 < r){
				int mid = (l + r)>>1;
				if(toBase(mask, mid) <= n) l = mid;
				else r = mid;
			}
			if(l > 1 and toBase(mask, l) == n){
				ans.insert(l);
			}	
		}
		cout << ans.size() << '\n';
		ans.clear();
	}

	return 0;
}

