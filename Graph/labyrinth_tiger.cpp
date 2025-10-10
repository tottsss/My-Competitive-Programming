#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
	if(min(i, j) < 0 or i > n or j > m) return 0;
	return 1;
}




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(dis, -1, sizeof(dis));
	memset(dis1, -1, sizeof(dis1));
	memset(dis2, -1, sizeof(dis2));
	pair<int, int> start = {1, 1}, finish = {-1, -1};
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'T'){
				 finish = {i, j};
			}
			if(a[i][j] == '#'){
				dis[i][j] = INF;
				dis1[i][j] = INF;
				dis2[i][j] = INF;	
			} 
		}
	}
	queue<pair<int, int> > q;
	p[finish.ff][finish.ss] = {-1,-1};
	dis[finish.ff][finish.ss] = 0;
	q.push(finish);
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 4; k++){
			int ni = v.ff + dx[k];
			int nj = v.ss + dy[k];
			if(in(ni, nj) and dis[ni][nj] == -1){
				dis[ni][nj] = dis[v.ff][v.ss]+1;
				p[ni][nj] = v;
				q.push({ni, nj});
			}
		}
	}
	
	dis1[start.ff][start.ss] = 0;
	q.push(start);
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 4; k++){
			int ni = v.ff + dx[k];
			int nj = v.ss + dy[k];
			if(in(ni, nj) and dis1[ni][nj] == -1 and (dis[ni][nj] == -1 or dis1[v.ff][v.ss]+1 < dis[ni][nj])){
				dis1[ni][nj] = dis1[v.ff][v.ss]+1;
				q.push({ni, nj});
			}
		}
	}
	start = {n-2, m-2};
	dis2[start.ff][start.ss] = 0;
	q.push(start);
	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for(int k = 0;k < 4; k++){
			int ni = v.ff + dx[k];
			int nj = v.ss + dy[k];
			if(in(ni, nj) and dis2[ni][nj] == -1){
				dis2[ni][nj] = dis2[v.ff][v.ss]+1;
				q.push({ni, nj});
			}
		}
	}
	cout << dis2[1][1] << '\n';
	if(dis1[n-2][m-2] == -1) cout << "No";
	else cout << "Yes";
	//https://acmp.ru/index.asp?main=task&id_task=804
	return 0;
}

