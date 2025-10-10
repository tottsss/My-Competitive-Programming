#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 20000;
vector<int> g[N+1];
int in[N+1], up[N+1], T, used[N+1], idx[N+1];
map<pair<int, int>, int > mp;
int n, m;
void dfs(int v, int p){
	used[v] = 1;
	in[v] = up[v] = ++T;
	for(int to : g[v]){
		if(used[to] == 0){
			dfs(to, v);
			up[v] = min(up[v], up[to]);
		}else if(to != p){
			up[v] = min(up[v], in[to]);
		}
	} 
	if(v != p and in[v] <= up[v]){
		mp[{min(v, p), max(v, p)}]--;
	}
}
int comp = 1;
void dfs_2(int v){
	used[v] = 1, idx[v] = comp;
	for(int to : g[v]){
		if(used[to]) continue;
		if(mp[{min(v, to), max(v,to)}]){
			dfs_2(to);
		}
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		mp[make_pair(min(a, b), max(a, b))]++;
	}
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			dfs(i, i);
		}
	}
	for(int i = 1;i <= n; i++) used[i] = 0;
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			dfs_2(i);
			comp++;
		}
	}
	cout << comp-1 << '\n';
	for(int i = 1;i <= n; i++) cout << idx[i] << " ";
//	cout << ans;
	return 0;
}

