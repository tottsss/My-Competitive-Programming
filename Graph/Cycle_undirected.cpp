#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int N = 1e5 + 10;
vector<int> g[N];
int par[N], used[N];
vector<int> ans;
void dfs(int v, int p){
	if(!ans.empty()) return;
	used[v] = 1;
	par[v] = p;
	for(int to : g[v]){
		if(used[to] == 0){
			dfs(to, v);
		}else if(ans.empty() and used[to] == 1 and to != p){
			for(int last = v; last != to and last != -1; last = par[last]){
				ans.push_back(last);
			} 
			ans.push_back(to);
			reverse(ans.begin(), ans.end());
			return;
		}
	}
	used[v] = 2;
}
 
main(){
	int n, m; cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[b].push_back(a);
		g[a].push_back(b);
	}
	for(int i = 1;i <= n; i++){
		if(used[i] == 0) dfs(i, i);
	}
	if(ans.empty()){
		cout << "No" << '\n';
	}else{
		cout << "Yes" << '\n'; 
		int v = ans.back();
		ans.pop_back();
		cout << ans.size()+1 << '\n';
		for(int x : ans) cout << x << ' ';
		cout << v;
	}
	return 0;
}
