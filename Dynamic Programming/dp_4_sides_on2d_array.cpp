#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e3;
int startA[N+1][N+1], startB[N+1][N+1];
int endA[N+1][N+1], endB[N+1][N+1];
int n, m;
int a[N+1][N+1];
/*
2 3
4 10 1
1 10 5
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n >> m;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			cin >> a[i][j];
		}
	}
	startA[1][1] = a[1][1];
	startB[n][1] = a[n][1];
	endA[n][m] = a[n][m];
	endB[1][m] = a[1][m];
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			if(i+1 <= n) startA[i+1][j] = max(startA[i+1][j], startA[i][j] + a[i+1][j]);
			if(j+1 <= m) startA[i][j + 1] = max(startA[i][j + 1], startA[i][j] + a[i][j + 1]);
		}
	}
	for(int i = n;i >= 1; i--){
		for(int j = 1;j <= m; j++){
			if(i-1 >= 1) startB[i-1][j] = max(startB[i-1][j], startB[i][j] + a[i-1][j]);
			if(j+1 <= m) startB[i][j + 1] = max(startB[i][j + 1], startB[i][j] + a[i][j + 1]);
		}
	}
	for(int i = n;i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(i-1 >= 1) endA[i-1][j] = max(endA[i-1][j], endA[i][j] + a[i-1][j]);
			if(j-1 >= 1) endA[i][j-1] = max(endA[i][j-1], endA[i][j] + a[i][j-1]);
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j = m;j >= 1; j--){
			if(i+1 <= n) endB[i+1][j] = max(endB[i+1][j], endB[i][j] + a[i+1][j]);
			if(j-1 >= 1) endB[i][j-1] = max(endB[i][j-1], endB[i][j] + a[i][j-1]);
		}
	}
	int mx = 0;
	for(int i = 2;i < n; i++){
		for(int j = 2;j < m; j++){
			mx = max(mx, startA[i-1][j] + endA[i+1][j] + startB[i][j-1] + endB[i][j+1]);
			mx = max(mx, startA[i][j-1] + startB[i+1][j] + endA[i][j+1] + endB[i-1][j]);
		}
	}
	cout << mx;
	return 0;
}

