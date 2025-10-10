#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 998244353;
int n, k;
int dp[1001][4][3001];

map<int, string> mp;

bool same(bool a, bool b){
	if((a and b) or (!a and !b)) return true;
	return false;
}


int comp(int a, int b){
	bool a1 = (b&(1<<0));
	bool a2 = (b&(1<<1));
	int c = 0;
	if(same(a2, a1)){
		a1 = (b&(1<<0));
		a2 = (a&(1<<0));
		if(same(a1, a2)) return 0;
		a1 = (b&(1<<1));
		a2 = (a &(1<<1));
		if(same(a1, a2)) return 0;
		return 1;
	}else{
		a1 = (a&(1<<0));
		a2 = (b&(1<<0));
		if(same(a1, a2) == false) c++;
		a1 = (a & (1<<1));
		a2 = (b&(1<<1));
		if(same(a1, a2) == false) c++;
		return c;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	dp[1][0][1] = 1;
	dp[1][1][2] = 1;
	dp[1][2][2] = 1;
	dp[1][3][1] = 1;
	// 00 -> 0
	// 01 -> 1
	// 10 -> 2
	// 11 -> 3
	mp[0] = "00";
	mp[1] = "01";
	mp[2] = "10";
	mp[3] = "11";
//	
//	for(int a = 0; a < 4; a++){
//		for(int b = 0; b < 4; b++){
//			cout << mp[a] << ' ' << mp[b] << '\n';
//			cout << comp(a, b) << '\n';
//		}
//	}
//	
	for(int i = 2;i <= n; i++){
		for(int K = 1; K <= k; K++){
			for(int pref = 0; pref < 4; pref++){
				if(dp[i-1][pref][K] == 0) continue;
				for(int last = 0; last < 4; last++){
					int C = comp(pref, last);
					dp[i][last][K+C] = (dp[i][last][K+C] + dp[i-1][pref][K])%M;
				}
			}
		}
	}
	
	int sum = 0;
	for(int mask = 0; mask < 4; mask++){
		sum = (sum + dp[n][mask][k])%M;
	}
	cout << sum;
	return 0;
}

