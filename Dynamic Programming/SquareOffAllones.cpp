#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


void solve(){
	int n; cin >> n;
	int m; cin >> m;
	vector< vector<int> > a(n+1, vector<int>(m+1,0));
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			cin >> a[i][j];
		}
	}
	function<int(int)> good=[&](int len){
		vector< vector<int> > dp(n+1, vector<int>(m+1,0));
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= m; j++){
				dp[i][j] = (a[i][j] >= len);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0;j < m; j++){
				dp[i+1][j+1] += dp[i+1][j] + dp[i][j+1] -dp[i][j]; 
			}
		}	
		
		function<int(int, int, int, int)> get=[&](int x, int y, int x1, int y1){
			return dp[x1][y1] + dp[x-1][y-1] - dp[x1][y-1] - dp[x-1][y1];	
		};
		
		for(int i = 1;i + len-1 <= n; i++){
			for(int j = 1;j + len-1 <= m; j++){
				if(get(i, j, i + len-1, j + len-1) >= len*len){
					return 1;
				}
			}
		}
		
		return 0;
	};
	
	int l = 0, r = min(n, m);
	if(good(r)){
		cout << r;
		return;
	}
	while(l + 1 < r){
		int mid = (l + r)>>1;
		if(good(mid)) l = mid;
		else r = mid;
	}
	cout << l;
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
