#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 4e5;
const int LOG = 20;
int up[N+10][LOG], depth[N+10];
vector<int> g[N+10];
int used[N+10], par[N+10], num;
int n, m, q;
void dfs(int v, int p){
	up[v][0] = p;
	used[v] = 1;
	for(int to : g[v]){
		if(used[to]) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
	}
}
int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}
void union_set(int a, int b){
	a = find_set(a), b = find_set(b);
	g[num].push_back(a);
	if(a!=b) g[num].push_back(b);
	par[num] = num; par[a] = par[b] = num, 
	num++;
}
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a,b);
	int k = depth[b]-depth[a];
	for(int i = 0;i < LOG; i++){
		if(k&(1<<i)){
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			b = up[b][i], a = up[a][i];
		}
	}
	return up[a][0];
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	num = n;
	for(int i = 0;i < n+m; i++) par[i] = i;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b; a--, b--;
		union_set(a,b);
	}
	for(int i = num-1; i >= 0; i--){
		if(used[i] ==0){
			dfs(i, i);
		}
	}
	for(int i = 1;i < LOG; i++){
		for(int v = 0; v < num; v++){
			up[v][i] = up[up[v][i-1]][i-1];
		}
	}
	while(q--){
		int a, b; cin >> a >> b; a--, b--;
		if(a == b){
			cout << 0 << '\n';
			continue;
		}
		int A = find_set(a), B = find_set(b);
		if(A != B){
			cout << "-1\n";
			continue;
		}
		cout << lca(a, b)-n+1 << '\n';
	}
	return 0;
}

