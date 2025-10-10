#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int n, m, k;
main(){
	// problem 580D
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	vector< vector<int> > dp((1<<19), vector<int>(n, INT_MIN));
	vector<vector<int> > g(n, vector<int>(n, 0));
	for(int i = 0;i < k; i++){
		int x, y, c; cin >> x >> y >> c;
		x--, y--;
		g[x][y] = c;
	}
	for(int i = 0;i < n; i++) dp[1<<i][i] = a[i];
	for(int mask = 1; mask < (1<<n); mask++){
		for(int last = 0;last < n; last++){
			if(mask&(1<<last)){
				for(int to = 0; to < n; to++){
					if(mask&(1<<to)) continue;
					dp[mask+(1<<to)][to] = max(dp[mask+(1<<to)][to], dp[mask][last] + a[to] + g[last][to]);
				}	
			}		
		}
	}
	int mx = 0;
	for(int mask = 0;mask < (1<<n); mask++){
		if(__builtin_popcount(mask)==m){
			for(int i = 0;i < n; i++){
				if(mask&(1<<i)) mx = max(mx, dp[mask][i]);
			}
		}
	}
	cout << mx;
	return 0;
}

