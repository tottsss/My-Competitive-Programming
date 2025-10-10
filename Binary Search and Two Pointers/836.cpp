#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 250;
int n, a[N+5][N+5];
int col[N+5][N+5], sz = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int in(int i, int j){
	if(max(i, j) >= n or min(i, j) < 0) return 0;
	return 1; 
}



void dfs(int i, int j, int cl, int cl1){
	col[i][j] = 1, sz++;
	for(int k = 0;k < 4; k++){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(!in(ni, nj) or col[ni][nj] != 0) continue;
		if(a[ni][nj] != cl and a[ni][nj] != cl1) continue;
		dfs(ni, nj, cl, cl1);
	}
}



main(){
   ifstream cin("multimoo.in");
   ofstream cout("multimoo.out");
	cin >> n;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
		}		
	}
	int mx = 0;
	vector<int> sizes;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			if(col[i][j] == 0){
				sz = 0;
				dfs(i, j, a[i][j], a[i][j]);
				mx = max(mx, sz);
			}
		}
	}
	cout << mx << '\n';
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++) col[i][j] = 0;
	}
	for(int i = 0;i < n; i++){
		for(int j = 1;j < n; j++){
			sz = 0;
			if(a[i][j] != a[i][j-1]){
				memset(col, 0, sizeof(col));
				dfs(i, j, a[i][j], a[i][j-1]);
				mx = max(mx, sz);
			}
		}
	}
	for(int i = 1;i < n; i++){
		for(int j = 0;j < n; j++){
			sz = 0;
			if(a[i][j] != a[i-1][j]){
				memset(col, 0, sizeof(col));
				dfs(i, j, a[i][j], a[i-1][j]);
				mx = max(mx, sz);
			}
		}
	}
	cout << mx;
	return 0;
}

