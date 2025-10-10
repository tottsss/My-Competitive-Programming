#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int LOG = 25;
vector<int> g[N+1];
int up[N+1][LOG+1],depth[N+1], sub[N+1];
int tin[N+1], tout[N+1], T;
int n, q;
void dfs(int v, int p){
	tin[v] = ++T;
	up[v][0] = p;
	for(int i = 1;i < LOG; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	sub[v] = 1;
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
		sub[v]+= sub[to];
	}
	tout[v] = ++T;
}


int isAnc(int v, int p){
	return (tin[v] >= tin[p] and tout[v] <= tout[p]);
}

int go_k(int a, int k){
	for(int i = 0;i < LOG; i++){
		if(k& (1 << i)){
			a = up[a][i];
		}
	}
	return a;
}
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	b = go_k(b, d);
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}
int dist(int a, int b, int par){
	if(par == -1) par = lca(a, b);
	return depth[a] + depth[b] - depth[par]*2;
}

int kth_on_path(int a, int b, int k, int par){
	if(depth[a] - depth[par] >= k){
		return go_k(a, k);
	}
//	cout << (depth[par] - depth[b]) - (k - (depth[a] - depth[par])) << "\n";
	return go_k(b, (depth[b] - depth[par]) - (k - (depth[a] - depth[par])));
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2;i <= n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		if(x == y){
			cout << n << '\n';
			continue;
		}
		int lc = lca(x, y);
		int d = dist(x, y, lc);
		if(d%2==1){
			cout << 0 << '\n';
			continue;
		}
		int orto = kth_on_path(x, y, d/2, lc);
		if(isAnc(x, orto) and isAnc(y, orto)){
			cout << n - sub[go_k(x, depth[x] - depth[orto] - 1)] - sub[go_k(y, depth[y] - depth[orto] - 1)] << '\n';
			continue;
		} 
		if(isAnc(orto, x)){
			cout << sub[orto] - sub[go_k(y, depth[y] - depth[orto] - 1)];	
		}else if(isAnc(orto, y)){
			cout << sub[orto] - sub[go_k(x, depth[x] - depth[orto] - 1)];	
		}else{
			if(depth[x] < depth[y]) swap(x, y);
			int X = go_k(x, d / 2 - 1);
			cout << sub[up[X][0]] - sub[X];
		}
		cout << '\n';
	}
	return 0;
}