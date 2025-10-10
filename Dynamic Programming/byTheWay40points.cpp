#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod =998244353;
int dp[2][311][311];
int n, m;
vector< pair<int, int> > p;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	p.resize(n);
	for(int i = 0;i < n; i++){
		cin >> p[i].ff >> p[i].ss;
	}
	dp[0][0][0] = 1;
	int xr = 1;
	for(int round = 1; round <= m; round++, xr^= 1){
		for(int x = 0; x <= 300; x++){
			for(int y = 0; y <= 300; y++){
				dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x+1][y]) % mod;
				dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x][y+1]) % mod;
				if(y-1 < 0){
					dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x][y+1]) % mod;
				}else{
					dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x][y-1]) % mod;
				}
				if(x-1 < 0){
					dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x+1][y]) % mod;
				}else{
					dp[xr][x][y] = (dp[xr][x][y] + dp[xr^1][x-1][y]) % mod;
				}
			}
		}
		// https://codeforces.com/group/COtOPg5tbB/contest/454249/problem/A
		for(int x = 0; x <= 300; x++) 
			for(int y = 0; y <= 300; y++) dp[xr^1][x][y] = 0;
	}
	int all = 0;
	for(int x = -300; x <= 300; x++){
		for(int y = -300; y <= 300; y++){
			int ans = 1;
			for(int i = 0;i < n; i++){
				int  X = abs(x - p[i].ff);
				int Y  = abs(y - p[i].ss);
				if(X+Y <= m){
//					cout << x << ' ' << y << " = " << dp[xr^1][X][Y] << '\n';
					ans = (ans * dp[xr^1][X][Y]) % mod;
				}else{
					ans = 0;
					break;
				}
			}
			all = (all + ans) % mod;
		}

	}
	cout << all;
	return 0;
}

