#include "soccer.h"
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 
int n;
vector< vector<int> > a;
vector<vector<int> > R, C;
/*
5
1 1 1 1 1
1 1 1 1 1
1 0 0 0 1
1 0 0 0 1
1 0 1 0 1
*/
 
/*
5
1 0 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 0 0
 
*/
 
int counter(int i, int j, int x, int y){
	int c = 0;
	while(i >= 0 && i < n && j < n && j >= 0){
		c+= (a[i][j] == 0);
		i+= x, j+= y;
	}
	return c;
}
 
 
int row_ones(int row, int i, int j){
	if(i > j) swap(i, j);
	return R[row][j] - (i == 0 ? 0 : R[row][i-1]);
}
 
int col_ones(int col, int i, int j){
	if(i > j) swap(i, j);
	return C[col][j] - (i == 0 ? 0 : C[col][i-1]);
}
 
int check(int i, int j, int r, int c){
	int ok = 0;
	if(row_ones(i, j, c) + col_ones(c, i, r) > 0) ok++;
	if(col_ones(j, i, r) + row_ones(r, j, c) > 0) ok++;
	if(ok != 2) return 1;
	return 0;
}
 
int biggest_stadium(int N, vector<vector<int>> F){
	n = N;
	a = F;
	R.resize(N);
	C.resize(N);
	int ans = 0;
	vector< pair<int, int> > cell;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			ans+= (a[i][j] == 0);
			if(a[i][j] == 0)
			cell.push_back({i, j});
		}
	}
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			R[i].push_back((R[i].empty() ? 0 : R[i].back()) + (a[i][j] == 1));
		}
	}
	for(int j = 0;j < n; j++){
		for(int i = 0;i < n; i++){
			C[j].push_back((C[j].empty() ? 0 : C[j].back()) + (a[i][j] == 1));
		}
	}
	if(ans == n * n) return ans;
	if(n * n - ans == 1){
		int mx = 0;
		for(int i = 0;i < n; i++){
			for(int j = 0;j < n; j++){
				if(a[i][j] == 0) continue;
				int west = counter(i, j, -1, 0);
				int east = counter(i, j, 1, 0);
				int north = counter(i, j, 0, -1);
				int south = counter(i, j, 0, 1);
				return ans - min(west, east)* min(north, south);
				
			}
		}
		return mx;
	}
	int sz = cell.size();
	if(N <= 3){
		ans = 0;
		for(int mask = 0; mask < (1<<sz); mask++){
			int ok = 0;
			for(int i = 0;i < sz; i++){
				if(mask & (1<<i)){
					for(int j = 0;j < sz; j++){
						if(mask & (1<<j) && i != j){
							if(!check(cell[i].ff, cell[i].ss, cell[j].ff, cell[j].ss)){
								ok = 1;
								break;
							}
						}
					}
				}
				if(ok) break;
			}
			if(!ok){
				ans = max(ans, __builtin_popcount(mask));
			}
		}
		
		return ans;
	}
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			for(int r = 0; r < n; r++){
				for(int c = 0; c < n; c++){
					if(a[i][j] == 0 and a[r][c] == 0){
						if(!check(i, j, r, c)){
							return 0;
						}
					}
				}
			}
		}
	}
	return ans;
}
 
 
//main(){
//	int N; cin >> N;
//	vector< vector<int> > F(N, vector<int>(N));
//	for(int i = 0;i < N; i++){
//		for(int j = 0;j < N; j++){
//			cin >> F[i][j];
//		}
//	}
//	cout << biggest_stadium(N, F);
//}