#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int INF = 1e9;
const int N = 1000;
int n, m;
char a[N][N];
int dis[N][N], dis2[N][N], dis1[N][N];
int dx_horse[] = {2,2,-2,-2, 1, 1, -1, -1};
int dy_horse[] = {1,-1, -1,1, 2, -2, -2, 2};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> p[N][N];
int in(int i, int j){
	if(min(i, j) < 0 or i >= n or j >= m) return 0;
	return 1;
}
map<pair<int, int>, char> Move;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(dis, -1, sizeof(dis));
	memset(dis1, -1, sizeof(dis1));
	Move[{0, 1}] = 'R';
	Move[{0, -1}] = 'L';
	Move[{-1, 0}] = 'U';
	Move[{1, 0}] = 'D';
	pair<int, int> start = {1, 1};
	vector<pair<int, int> > end;
	vector<pair<int, int> >  monster;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'A') start = {i, j};
			if(a[i][j] == 'M') monster.push_back({i, j});
			if((i == n-1 or j == m-1 or i == 0 or j == 0) and a[i][j] != '#'){
				end.push_back({i, j});
			} 
			if(a[i][j] == '#'){
				dis[i][j] = INF;
				dis1[i][j] = INF;	
			}
		}
	}
	if(end.empty()){
		cout << "YES" << '\n';
		cout << 0;
		return 0;
	}
	queue<pair<int, int> > q;
	for(auto finish : monster){
		dis[finish.ff][finish.ss] = 0;
		q.push(finish);
	}
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 4; k++){
			int ni = v.ff + dx[k];
			int nj = v.ss + dy[k];
			if(in(ni, nj) and dis[ni][nj] == -1){
				dis[ni][nj] = dis[v.ff][v.ss]+1;
				q.push({ni, nj});
			}
		}
	}
	dis1[start.ff][start.ss] = 0;
	p[start.ff][start.ss] = {-1, -1};
	q.push(start);
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 4; k++){
			int ni = v.ff + dx[k];
			int nj = v.ss + dy[k];
			if(in(ni, nj) and dis1[ni][nj] == -1 and (dis[ni][nj] == -1 or dis1[v.ff][v.ss]+1 < dis[ni][nj])){
				dis1[ni][nj] = dis1[v.ff][v.ss]+1;
				p[ni][nj] = v;
				q.push({ni, nj});
			}
		}
	}
	for(auto e : end){
		if(dis1[e.ff][e.ss] != -1 and dis1[e.ff][e.ss] != INF){
			cout << "YES" << '\n';
			cout << dis1[e.ff][e.ss] << '\n';
			vector<char> path;
			pair<int, int> pref = {e.ff, e.ss};
			for(pair<int, int> par = p[e.ff][e.ss]; par.ff != -1; par = p[par.ff][par.ss]){
				path.push_back(Move[{-par.ff + pref.ff, -par.ss+pref.ss}]);
				pref = par;
			}
			reverse(all(path));
			for(auto c : path) cout<<c;
			return 0;
		}
	}
	cout << "NO";
	
	return 0;
}

