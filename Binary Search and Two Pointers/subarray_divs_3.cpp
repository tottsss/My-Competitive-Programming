#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

pair<int, int> ans;

void A(pair<int, int> range){
	if(ans.ss - ans.ff < range.ss-range.ff) ans = range;
	else if(ans.ss - ans.ff == range.ss - range.ff){
		if(ans.ff > range.ff) ans = range;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	ans = {n+n, -n};
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	map<int, int> mp;
	mp[0] = 0;
	int sum = 0;
	for(int i = 0;i < n; i++){
		sum = (sum+a[i])%3;
		if(sum < 0) sum+= 3;
		if(mp.count(sum%3)){
			A({mp[sum%3], i});
		}
		if(mp.count(sum%3) == false){
			mp[sum%3] = i+1;
		}
	}
	if(ans.ss == -n) cout << "-1";
	else
	cout << ans.ff+1 << ' ' << ans.ss+1;
	return 0;
}

