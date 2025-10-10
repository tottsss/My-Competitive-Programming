#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 2e5+1;
vector<int> g[N], ans(N), c(N);
set<int> st[N];
int n;
 
void dfs(int v, int par){
	for(auto to : g[v]){
		if(to == par) continue;
		dfs(to, v);
		if(st[to].size() > st[v].size()) swap(st[to], st[v]);
		st[v].insert(st[to].begin(), st[to].end());
	}
	st[v].insert(c[v]);
	ans[v] = st[v].size();
}
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> c[i];
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1;i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}