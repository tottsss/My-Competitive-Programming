#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int M = 1e9;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int need; cin >> need;
	vector<int> a(n+1);
	for(int i = 1;i <= n; i++) cin >> a[i];
	vector<int> dp(N, 0), p(N, -1);
	dp[0] = 1, p[0] = -1;
	for(int i = 1;i <= n; i++){
		if(dp[need]>1){
			cout << -1;
			return 0;
		}
		for(int S = need; S >= a[i]; S--){
			dp[S]+= dp[S-a[i]];
			if(dp[S-a[i]] and p[S] == -1) p[S] = S - a[i];
		}
	}
	vector<int> path;
	if(dp[need] > 1){
		cout << "-1";
		return 0;
	}
	if(dp[need] == 0){
		cout << 0;
		return 0;
	}
	int pref = need;
	for(int par = p[need]; par != -1; par = p[par]){
		path.push_back(abs(par - pref));
		pref = par;
	}
	cout << path.size() << '\n';
	sort(all(path));
	for(int x : path) cout << x << ' ';
	if(accumulate(all(path), 0LL) != need) assert(false);
	
	return 0;
}