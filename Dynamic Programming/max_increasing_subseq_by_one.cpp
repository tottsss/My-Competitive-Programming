#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, vector<int> > mp;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	vector<int> dp(n, 1);
	for(int i = 0;i < n; i++){
		int to = upper_bound(all(mp[a[i]+1]), i) - mp[a[i]+1].begin();
		if(to < mp[a[i]+1].size() and mp[a[i]+1][to] < n){
			dp[mp[a[i]+1][to]] = max(dp[mp[a[i]+1][to]], dp[i]+1);	
		}
	}
	int id =0;
	for(int i = 1;i < n; i++){
		if(dp[id] <dp[i]){
			id = i;
		}
	}
	// https://codeforces.com/problemset/problem/977/F
	cout << dp[id] << "\n";
	vector<int> p;
	while(true){
		p.push_back(id + 1);
		int to = lower_bound(all(mp[a[id]-1]), id) - mp[a[id]-1].begin();
		to--;
		if(to >= 0 and to < mp[a[id]-1].size() and id > mp[a[id]-1][to]){
			id = mp[a[id]-1][to];
		}else break;
	}
	reverse(all(p));
	for(int x : p) cout << x << " ";
	return 0;
}

