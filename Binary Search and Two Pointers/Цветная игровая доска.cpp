#include "bits/stdc++.h"

using namespace std;
#define int long long
const int M = 1e9 + 7;
int getnum(int i, int j){
	int ans = i + j;
	ans--;
	ans %= 7;
	return ans == 0 ? 7 : ans;
}
signed main () {
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	int l = 0, r = 2e9;
	int s = n*m-1;
	while(l < r){
		int mid = (l+r+1)/2;
		int cur = (n-mid*2);
		int res = (m-mid*2);
		if(cur <= 0 or res <= 0){
			r = mid-1;
			continue;
		}
		if(s - (n-mid*2)*(m-mid*2) > k)r = mid-1;
		else l = mid;
	}
	if(k == 0){
		cout << 1 << endl;
		return 0;
	}
//	cout << l << ' ' << r << '\n';
	// cout <<  << endl;
	r = l;
	int use = s-(n-r*2)*(m-r*2);
	if(k <= m-1+n-1+m-1+n-2){
		if(k <= m-1){
			cout << getnum(1, 1+k) << endl;
			return 0;
		}
		k-=(m-1);
		if(k <= n-1){
			cout << getnum(1+k, m) << endl;
			return 0;
		}
		k-=(n-1);
		if(k <= m-1){
			cout << getnum(n, m-k) << endl;
			return 0;
		}
		k-=(m-1);
		cout << getnum(n-k, 2) << endl;
		return 0;
	}else{
		k-=use;
		if(k <= m-r*2){
			cout << getnum(r+1, r+k) << endl;
			return 0;
		}
		k-=(m-r*2);
		if(k <= n-r*2-1){
			cout << getnum(r+k+1, m-r) << endl;
			return 0;
		}
		k-=(n-r*2-1);
		if(k <= m-r*2-1){
			cout << getnum(n-r, m-r-k) << endl;
			return 0;
		}
		k-=(m-r*2-1);
		cout << getnum(n-k-r, r+1) << endl;
		return 0;
	}
	return 0;
} 