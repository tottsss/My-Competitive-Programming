#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 7;
#define ff first
#define ss second
const int N = 1e5+5;
int n, m, timer = 0; // number of nodes
vector<int> used(N, 0), tin(N, -1), low(N, -1), g[N];
set<int> Points;
void dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = low[v] = timer++;
    int children=0;
    for(int to : g[v]){
        if(to == p) continue;
        if(used[to] == 1) {
            low[v] = min(low[v], tin[to]);
        }else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                Points.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        Points.insert(v);
}
 
void find_cutpoints() {
    for(int i = 1; i <= n; ++i){
        if(used[i] == 0)
            dfs (i);
    }
}
 
main(){
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b, w; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		
	}
	
	find_cutpoints();
	cout << Points.size() << "\n";
	for(auto to : Points) cout << to << " ";
	
	return 0;
}