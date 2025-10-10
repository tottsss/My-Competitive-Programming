#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int INF = 1e9;
const int N = 50;
int n;
char a[N][N];
int dis[N][N], used[N][N];
int dx_horse[] = {2,2,-2,-2, 1, 1, -1, -1};
int dy_horse[] = {1,-1, -1,1, 2, -2, -2, 2};
pair<int, int> p[N][N];
int in(int i, int j){
	if(min(i, j) < 0 or max(i, j) >= n) return 0;
	return 1;
}




main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);
	cin >> n;
	memset(dis, -1, sizeof(dis));
	pair<int, int> start = {-1, -1}, finish = {-1, -1};
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == '@'){
				if(start.ff== -1) start = {i, j};
				else finish = {i, j};
			}
			if(a[i][j] == '#') dis[i][j] = INF;
		}
	}
	queue<pair<int, int> > q;
	p[start.ff][start.ss] = {-1,-1};
	dis[start.ff][start.ss] = 0;
	q.push(start);
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 8; k++){
			int ni = v.ff + dx_horse[k];
			int nj = v.ss + dy_horse[k];
			if(in(ni, nj) and dis[ni][nj] == -1){
				dis[ni][nj] = dis[v.ff][v.ss]+1;
				p[ni][nj] = v;
				q.push({ni, nj});
			}
		}
	}
	if(dis[finish.ff][finish.ss] == -1){
		cout << "Impossible";
	}else{
		for(pair<int, int> par = finish; par.ff != -1; par = p[par.ff][par.ss]){
			used[par.ff][par.ss] = 1;
		}
		
		for(int i = 0;i < n; i++){
			for(int j = 0;j < n; j++){
				if(used[i][j]) cout << '@';
				else cout << a[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}

