#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
const int LOG = 20;
vector<int> g[N+1],root, sub[N+1];
int up[N + 1][LOG + 1], tin[N+1], tout[N+1], T;
int n, p[N+1], depth[N+1];
void dfs(int v, int p){
	tin[v] = ++T;
	up[v][0] = p;
	for(int i = 1;i < LOG; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	sub[depth[v]].push_back(tin[v]);
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
	}
	tout[v] = ++T;
}

int kth(int v, int k){
	for(int i = 0;i < LOG; i++){
		if(k&(1<<i)){
			v = up[v][i];
		}
	}
	return v;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> p[i];
		if(p[i] == 0){
			root.push_back(i);
			continue;
		}
		g[i].push_back(p[i]);
		g[p[i]].push_back(i);
	}
	for(int rt : root){
		dfs(rt, 0);
	}
	int q; cin >> q;
	while(q--){
		int x, p; cin >> x >> p;
		int dad = kth(x, p);
		if(dad <= 0){
			cout << 0 << " ";
			continue;
		}
		int L = lower_bound(all(sub[depth[x]]), tin[dad]) - sub[depth[x]].begin();
		int R = upper_bound(all(sub[depth[x]]), tout[dad]) - sub[depth[x]].begin();
		cout << max(0, R-L-1) << ' ';
	}
	return 0;
}