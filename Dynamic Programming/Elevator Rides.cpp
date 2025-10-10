#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<pair<int, int> > dp((1<<20));
//	vector<int> sum((1<<20), 0LL);
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
//	for(int mask = 0; mask < (1<<n); mask++){
//		for(int i = 0;i < n; i++){
//			if(mask & (1<<i)){
//				sum[mask]+= a[i];
//			}
//		}
//	}
//	sum[0] = 1;
	dp[0] = {1, 0};
	for(int mask = 1; mask < (1<<n); mask++){
		pair<int, int> best = {INT_MAX, INT_MAX};
		for(int i = 0;i < n; i++){
			if((mask & (1<<i)) == 0) continue;
//				cout << mask << " ";
			pair<int, int> res = dp[mask - (1<<i)];
			if(res.ss + a[i] > x) res.ss = a[i], res.ff++;
			else res.ss+= a[i];
			
			if(res.ff < best.ff) best= res;
			else if(res.ff == best.ff and best.ss > res.ss) best = res;
		}
		dp[mask] = best;
	}
	cout << dp[(1<<n)-1].ff;
	return 0;
}