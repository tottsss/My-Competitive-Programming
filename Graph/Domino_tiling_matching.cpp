#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e5;

long long ans;
int n, m, a, b;
vector<int> g[N];
int timer = 1, par[N], used[N];
char c[100][100];
int cell[100][100];
int try_kuhn(int v){
	if(used[v] == timer) return 0;
	used[v] = timer;
	for(int to : g[v]){
		if(par[to] == 0){
			par[to] = v;
			return 1;
		}
	}
	for(int to : g[v]){
		if(try_kuhn(par[to])){
			par[to] = v;
			return 1;
		}
	}
	return 0;
}
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int in(int i, int j){
	if(min(i, j) < 0 or i >= n or j >= m) return 0;
	return 1;
}

int get(int i, int j){
	if((i+j)%2==0) return 1;
	return 0;
}


void add_edges(){
	int cl = 1;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			if(c[i][j] == '*'){
				cell[i][j] = cl++;
			}
		}
	}
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			if(c[i][j] == '*' and get(i, j)==1){
				for(int k = 0;k < 4; k++){
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(in(ni, nj) and c[ni][nj] == '*' and get(ni, nj) == 0){
						g[cell[i][j]].push_back(cell[ni][nj]);
					}
				}
			}
		}
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	int z = 0;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> c[i][j];
			z+= (c[i][j] == '*');
		}
	}
	if(a >= b*2){
		cout << z*b;
		return 0;
	}
	add_edges();
	for(int i = 1;i <= z; i++){
		if(try_kuhn(i)){
			timer++;
		}
	}
	timer--;
	cout << timer * a + (z - timer*2) * b;
	return 0;
}

