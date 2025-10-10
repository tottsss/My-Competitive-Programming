#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
const int N = 1e5 + 1;
vector<int> g[N], G[N], topologic, used(N, 0), idx(N, 0);
int num = 1;
void dfs(int v){
	used[v] = 1;
	for(auto to : g[v]){
		if(used[to] == 0){
			dfs(to);
		}
	}
	topologic.push_back(v);
}
 
void dfs_2(int v){
	used[v] = 1;
	idx[v] = num;
	for(auto to : G[v]){
		if(used[to] == 0){
			dfs_2(to);
		}
	}
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		G[b].push_back(a);
	}	
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			dfs(i);
		}
	}
	for(int i = 1;i <= n; i++){
		used[i] = 0;
	}
	reverse(topologic.begin(), topologic.end());
	for(auto to : topologic){
		if(used[to] == 0){
			dfs_2(to);
			num++;
		}
	}
	cout << num-1 << "\n";
	for(int i = 1;i <= n; i++){
		cout << idx[i] << " ";
	}
	return 0;
}