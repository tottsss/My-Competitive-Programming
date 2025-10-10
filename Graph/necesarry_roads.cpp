#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int n, m;
vector<int> g[N+1];
map<pair<int, int>, int> mp;
int in[N+1], up[N+1], used[N+1];
int T;
vector<pair<int, int> > most;
void dfs(int v, int p){
	in[v] = up[v] = ++T;
	used[v] = 1;
	for(int to : g[v]){
		if(used[to] == 0){
			dfs(to, v);
			up[v] = min(up[v], up[to]);
		}else if(to != p){
			up[v] = min(up[v], in[to]);		
		}
	}
	if(in[v] == up[v] and p != v){
		most.push_back({min(p, v), max(p, v)});
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		mp[{min(a, b), max(a, b)}] = i;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			dfs(i, i);
		}
	}
	cout << most.size() << '\n';
	for(auto x : most) cout << x.ff << ' ' << x.ss << "\n";
	return 0;
}

