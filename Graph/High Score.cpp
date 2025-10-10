#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e18 + 7;
const int N = 5000 + 1;
vector<int> g[N], used(N, 0);
set<int> edit, road;
int f = 0;
int cycle = 0;
 
void dfs(int v){
	used[v] = 1;
	if(f == 0) road.insert(v);
	for(auto to : g[v]){
		if(used[to] == 0){
			dfs(to);
		}
	}
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector< pair<int, pair<int, int> > > edge;
	for(int i = 0;i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back(b);
		edge.push_back({c, {a, b}});
	}
	vector<int> dis(n + 1, -INF);
	dis[1] = 0;
	for(int i = 0;i < n; i++){
		for(auto e : edge){
			int a, b, w; w = e.ff; a = e.ss.ff; b=e.ss.ss;
			if(dis[b] < dis[a] + w){
				if(i == n-1){
					edit.insert(b);
				}
				dis[b] = dis[a] + w;
			}
		}
	}	
	dfs(1);
	f = 1;
	for(int i = 1; i <= n; i++){
		if(edit.count(i) == false or road.count(i) == false) continue;
		for(int j = 1;j<= n; j++){
			used[j] = 0;
		}
		dfs(i);
		if(used[n] == 1){
			cycle = 1;
		}
		
	}
	if(cycle == 1){
		cout << "-1";
	}else{
		cout << dis[n];
	}
	return 0;
}