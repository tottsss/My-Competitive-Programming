// Problem: F. Xor-пути
// Contest: Codeforces - Codeforces Round #498 (Div. 3)
// URL: https://codeforces.com/contest/1006/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
map<long long, long long> dp[21];
long long a[21][21],  k;
int n,m;

void begin(int i, int j, long long x){
	if(i > n or j > m) return;
	if((i + j) == (n + m) / 2 + 1){ 
		dp[i][x ^ a[i][j]]++;
		return;
	}
	begin(i + 1, j, x ^ a[i][j]);
	begin(i, j + 1, x ^ a[i][j]);
}

long long end(int i, int j, long long x){
	if(i < 1 or j < 1) return 0;
	if((i + j) == (n + m) / 2 + 1){
		return dp[i][x];
	}
	return end(i-1, j, x^a[i][j]) + 
	end(i, j-1, x^a[i][j]);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			cin >> a[i][j];
		}
	}
	begin(1, 1, 0LL);
	cout << end(n, m, k);
	
	return 0;
}