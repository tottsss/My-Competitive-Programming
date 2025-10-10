#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5+1;
vector<int> g[N];
int used[N];
int cnt =0 ;
void dfs(int v, int p){
	for(auto to : g[v]){
		if(to == p) continue;
		dfs(to, v);
	}
	if(used[v] == 0 and used[p] == 0){
		used[v] = 1;
		used[p] = 1;
		cnt++;
	}
}
 
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	used[0] = 1;
	 int n; cin >> n;
	 for(int i = 0;i < n-1; i++){
	 	int a, b; cin >> a >> b;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	 }
	 dfs(1, 0);
	 cout << cnt;
	return 0;
}