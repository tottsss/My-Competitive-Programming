#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int dist(pair<int,int> a, pair<int, int> b){
	return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}

main(){
   ifstream cin("marathon.in");
   ofstream cout("marathon.out");
	int n, K; cin >> n >> K;
	vector<pair<int, int> > a(n);
	for(auto &e : a){
		cin >> e.ff >> e.ss;
	}
	vector< vector<int> > dp(n, vector<int>(n+n+1, INT_MAX));
	dp[0][0] = 0;
	for(int i = 1;i < n; i++){
		dp[i][0] = dp[i-1][0] + dist(a[i], a[i-1]);
		for(int j = 0;j < i; j++){
			for(int k = 0;k <= j; k++){
				dp[i][k+(i-j-1)] = min(dp[i][k+(i-j-1)], dp[j][k] + dist(a[i], a[j]));
			}		
		}
	}
	int mn = INT_MAX;
	for(int i = 0;i <= K; i++){
		mn = min(mn, dp[n-1][i]);
	}
	cout << mn;
	return 0;
}

