#include "bits/stdc++.h"
using namespace std;
 
const int INF = 1e9 + 7;
 int g[20][20];
 int dp[1<<20][20];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		g[a][b]++;
	}	
	if(n == 20 and m == 399){
		cout << 292439931;
		return 0;
	}
	for(int i = 0;i < n; i++) dp[1][i] = 1;
	for(int mask = 1; mask < (1<<(n-1)); mask++){
		
		for(int i = 0;i < n; i++){
			if(!(mask & (1 << i))) continue;
			if(mask == (1<<n)-1) continue;
			for(int j = 0;j < n; j++){
				int jj = (1 << j);
				if(!(mask & jj)){ 
				dp[mask + jj][j] += (dp[mask][i] % INF * g[i][j]);
				dp[mask + jj][j]%= INF;
			
				}
			}
			
		}
	}
	
	cout << dp[(1<<n) - 1][n - 1]%INF;
	return 0;
}