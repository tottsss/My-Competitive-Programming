#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


void solve(){
	int n, q; cin >> n >> q;
	vector<int> pref_max(n + 2,0), pref_min(n + 2,0);
	vector<int> suff_max(n+2,0), suff_min(n+2,0);
	vector<int> pref_sum(n + 2, 0), suff_sum(n+2,0);
	string s; cin >> s;
	vector<int> a; a.push_back(0);
	for(int i = 0;i < n; i++){
		a.push_back((s[i] == '+' ? 1 : -1));
	}
	for(int i = 1;i <= n; i++){
		pref_sum[i]+= pref_sum[i-1]+a[i];
		pref_max[i] = max(pref_max[i-1], pref_sum[i]);
		pref_min[i] = min(pref_min[i-1], pref_sum[i]);
	}
	for(int i = n;i > 0; i--){
		suff_sum[i] = suff_sum[i+1]+a[i];
		suff_max[i] = max(0LL, suff_max[i+1]+a[i]);
		suff_min[i] = min(0LL, suff_min[i+1]+a[i]);
	}
	while(q--){
		int l, r; cin >> l >> r;
		int MX = max(pref_max[l-1], pref_sum[l-1] + suff_max[r + 1]);
		int MN = min(pref_min[l-1], pref_sum[l-1] + suff_min[r + 1]);
		cout << MX-MN+1 <<'\n';
	}
}
//https://codeforces.com/contest/1473/problem/D

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
