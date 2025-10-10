#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 100;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   vector< vector< vector<int> > > dp(N+10, vector< vector<int> >(N+10, vector<int>(N+10, -1)));
	int n, k, d; cin >> n >> k >> d;
	vector<int> p(n+1,0);
	for(int i = 1;i <= n; i++){
		cin >> p[i];
	}
	for(int i = 0;i <= n; i++){
		dp[i][0][0] = 0;
	}
	/*
	
	You are given a sequence of non-negative integers
A=(a1​,a2​,…,aN​).
n<= 100, k<= 100, d<=100
Let
S be the set of non-negative integers that can be the sum of K terms in
A (with distinct indices).
Find the greatest multiple of
D in S. If there is no multiple of D in S, print -1 instead.
	*/
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= i; j++){
			for(int D = 0; D < d; D++){
				if(dp[i-1][j-1][D] != -1){
					int nx = (D + p[i])%d;
					dp[i][j][nx] = max(dp[i][j][nx], p[i] + dp[i-1][j-1][D]);
				}
				if(dp[i-1][j][D] != -1){
					dp[i][j][D] =max(dp[i][j][D], dp[i-1][j][D]); 
				}
			}
		}
	}
	cout << dp[n][k][0];
	return 0;
}

