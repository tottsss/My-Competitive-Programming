#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 500;
int m, n, t;
int in(int i, int j){
	if(min(i, j) < 0 or i >= n or j >= m) return 0;
	return 1;
}
int a[N][N], c[N][N], used[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int cnt;
vector<pair<int, int> > start;
void dfs(int i, int j, int d){
	used[i][j] = 1;
	cnt++;
	for(int k = 0;k < 4; k++){
		int ni = i + dx[k], nj = j + dy[k];
		if(in(ni, nj) and used[ni][nj]==0){
			if(abs(a[i][j] - a[ni][nj]) <= d) dfs(ni,nj, d);
		}
	}
}

main(){
	// but its time limit
	
	ifstream cin("skilevel.in");
	ofstream cout("skilevel.out");
	cin >> n >> m >> t;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> c[i][j];
			if(c[i][j]) start.push_back({i, j});
		}
	}
	int sum = 0;
	for(auto x : start){
		int l = -1, r = (int)1e9+1;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			dfs(x.ff, x.ss, mid);
			if(cnt >= t) r = mid;
			else l = mid;
			for(int i = 0;i < n; i++){
				for(int j = 0;j < m; j++) used[i][j] = 0;
			}
			cnt = 0;
		}
//		cout << r << endl;
		sum+= r; 
	}
	cout << sum;
	return 0;
}

