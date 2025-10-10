#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = (1<<30) + 1;
int dp[1111][1111];
int n, m;
bool can(int a, int b){
	for(int i = 0;i < m-1; i++){
		int c = (a & (1<<i));
		int c1 = (a & (1<<(i + 1)));
		int C = (b & (1<<i));
		int C1 = (b & (1<<(i + 1)));
		if(c and c1 and C and C1){
			return false;
		}
		if(!c and !c1 and !C and !C1){
			return false;
		}
	}
	return true;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n < m) swap(n,m);
	for(int mask = 0; mask < (1<<m); mask++){
		dp[1][mask]++;
	}
	for(int i = 2;i <= n; i++){
		for(int x = 0; x < (1<<m); x++){
			for(int y = 0;y < (1<<m); y++){
				if(can(x, y)){
					dp[i][y]+= dp[i-1][x];
				}
			}
		}
	}
	int sum = 0;
	for(int x = 0; x < (1<<m); x++){
		sum+= dp[n][x];
	}
	cout << sum;
	return 0;
}

