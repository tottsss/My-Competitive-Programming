#include "bits/stdc++.h"
using namespace std;
const int N = 2e5+1;
vector<int> g[N], down(N, 0), up(N,0);
 
void dfs(int v, int p){
	for(auto to : g[v]){
		if(p == to) continue;
		dfs(to, v);
		down[v] = max(down[v], down[to] + 1);
	}
}
 
void dfs2(int v, int p){
	priority_queue< pair<int, int> > q;
	for(auto to : g[v]){
		if(p == to) continue;
		up[to] = max(up[to], up[v]+1);
		q.push({down[to], to});
	}
	int mx1 = -1, mx2 = -1;
	if(!q.empty()){
		mx1 = q.top().second;
		q.pop();
	}
	if(!q.empty()){
		mx2 = q.top().second;
		q.pop();
	}
	for(auto to : g[v]){
		if(to == p) continue;
		if(to != mx1 and mx1 != -1){
			up[to] = max(up[to], down[mx1] + 2);
		}
		if(to != mx2 and mx2 != -1){
			up[to] = max(up[to], down[mx2] + 2);
		}
		dfs2(to, v);
	}
}
 
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, -1);
	dfs2(1, -1);
	for(int i = 1;i <= n; i++){
		cout << max(down[i], up[i]) << " ";
	}
	return 0;
}