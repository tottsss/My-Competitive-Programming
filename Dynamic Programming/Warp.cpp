#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 998244353;

void add_self(int &a, int b){
	a+= b;
	if(a < 0) a+= mod;
	if(a >= mod) a-= mod;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	int dp[n+1][n+1][n+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	set<pair<int, int> > st;
	for(int i = 0;i < m; i++){
		int x, y; cin >> x >> y;
		st.insert({x, y});
	}
	for(int i = 0;i <= n; i++){
		for(int j = 0;j <= n; j++){
			for(int k = 0;k <= n; k++){
				int x = i * a + j * c + k * e;
				int y = i * b + j * d + k * f;
				if(st.count({x, y})) continue;
				if(i) add_self(dp[i][j][k], dp[i-1][j][k]);
				if(j) add_self(dp[i][j][k], dp[i][j-1][k]);
				if(k) add_self(dp[i][j][k], dp[i][j][k-1]);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n; i++){
		for(int j = 0;j <= n; j++){
			for(int k = 0;k <= n; k++){
				int x = i * a + j * c + k * e;
				int y = i * b + j * d + k * f;
				if(st.count(x, y)) continue;
				if(i + j + k == n) add_self(ans, dp[i][j][k]);
			}
	
		}
	}
	cout << ans;
	return 0;
}

