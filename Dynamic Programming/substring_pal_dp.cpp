#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 500;
const int inf = 1e9;
int n;
int dp[N + 10][N + 10], pal[N + 10][N + 10];
vector<int> a;
int f(int l, int r){
	if(l >= r) return dp[l][r] = 1;
	if(dp[l][r] != -1) return dp[l][r];
	if(r == l+1){
		if(a[l] == a[r]) return dp[l][r] = 1;
		return dp[l][r] =2;
	}
	int M = inf;
	M = 1 + f(l+1, r);
	if(a[l] == a[r]){
		M = min(M, f(l+1, r-1));
	}
	for(int c = l;c < r; c++){
		M = min(M, f(l, c) + f(c + 1, r));
	}
	return dp[l][r] = M;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	memset(dp, -1, sizeof(dp));
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	cout << f(0, n-1) << '\n';
	return 0;
}