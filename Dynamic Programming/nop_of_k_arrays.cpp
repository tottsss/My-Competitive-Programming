#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

vector<int> tgc;
int used[1001], direct[1001][1001];
vector<int> g[1001], G[1001];
void dfs(int v){
	used[v] = 1;
	for(auto to : g[v]){
		if(used[to] == 0){
			dfs(to);
		}
	}
	tgc.push_back(v);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	while(k--){
		vector<int> a(n);
		for(auto &e : a) cin >> e;
		for(int i = 0;i < n; i++){
			for(int j = i+1;j < n; j++){
				direct[a[i]][a[j]] = 1;
			}
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			if(direct[i][j] and direct[j][i]==0){
				g[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	for(int i = 1;i <= n; i++){
		if(!used[i]){
			dfs(i);
		}
	}
	reverse(all(tgc));
	vector<int> path(n+1, 1);
	for(auto v : tgc){
		for(auto to : g[v]){
			path[to] = max(path[to], path[v]+1);
		}
	}
	cout << *max_element(all(path));
	return 0;
}

