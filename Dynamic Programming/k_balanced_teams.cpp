#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n + 1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	if(k == n){
		cout << n;
		return 0;
	}
	// https://codeforces.com/contest/1133/problem/E
	sort(a.begin() + 1, a.end());
	vector< vector<int> > dp(n+10, vector<int>(n+10, 0));
	for(int i = 1;i <= n; i++){
		int L = upper_bound(all(a), a[i] + 5) - a.begin();
		while(L >= a.size() or a[L] > a[i] + 5) L--;
		for(int to = i; to <= L; to++){
			dp[to][1] = max(dp[to][1], to-i+1);
		}
	}
	for(int i =1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			int L = upper_bound(all(a), a[i] + 5) - a.begin();
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			while(L >= a.size() or a[L] > a[i] + 5) L--;
			dp[L][j + 1] = max(dp[L][j + 1], dp[i-1][j] + (L-i+1));
		}
	}
	
	
	int mx = 0;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= min(i, k); j++){
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx;
	return 0;
}

