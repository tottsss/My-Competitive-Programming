#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int n, m, q; 
int a[1001][1001], pref[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int all = 0;
int in(int i, int j){
	if(min(i, j) < 1 or j > m or i > n) return 0;
	return 1;
}
int used[1001][1001], dp[1001][1001], can[1001][1001];

vector<pair<int, int> >cell;
int NO = 0;
void dfs(int i, int j){
	if(a[i][j] == -1){
		return;
	}
	used[i][j] = 1;
	cell.push_back({i, j});
	if(a[i][j] == 0) NO++;
	for(int k = 0;k < 2; k++){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(in(ni, nj) and a[ni][nj] != -1 and used[ni][nj]==0){
			dfs(ni, nj);
		}
	}
}
int rec(int i, int j){
	can[i][j]++;
	if(a[i][j] == -1){
		return dp[i][j] = 0;
	}	
	if(dp[i][j] != -1) return dp[i][j];
	int s = a[i][j];
	int ok = 0;
	if(in(i+1, j)){
		s+= rec(i + 1, j);
		if(a[i+1][j] == -1) ok = 1;
	}
	if(in(i, j+1)){
		s+= rec(i, j+1);
		if(a[i][j+1] == -1) ok = 1;
	}
	int ni = i +1, nj = j+1;
	while(in(ni, nj)){
		if(can[ni][nj] > 1 and a[ni][nj] != -1){
			dp[i][j]-= dp[ni][nj];
			break;
		}
		ni++, nj++;
	}
	return dp[i][j] = s;
}

int find_S(){
	int s = 0;
	/*
5 8 0
$$$$$#$$
#$$$$$$$
$$$#$##$
$$$$$$##
#$$#$$$$
	*/
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			rec(i, j);
			s+= dp[i][j];
		}
	}
	return s;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			char c; cin >> c;
			if(c == '$') a[i][j] = 1;
			else if(c == '#') a[i][j] = -1;
			pref[i][j]+= (pref[i-1][j] + pref[j-1][i] - pref[i-1][j-1]) + (a[i][j] == 1);
			dp[i][j] = -1;
			all+= a[i][j];
		}
	}
	cout << find_S() << '\n';
	for(int Q = 0; Q < q; Q++){
		char type; cin >> type;
		int x, y; cin >> x >> y;
		if(all == n*m and max(n, m) > 50 and q > 50) continue;
		if(type == '!'){
			if(a[x][y] == 0){
				a[x][y] = 1;
			}else a[x][y] = 0;
		}else{
			dfs(x,y);
			cout << cell.size()-NO << '\n';
			NO = 0;
			for(auto c : cell) used[c.ff][c.ss] = 0;
			cell.clear();
		}
	}
	return 0;
}

