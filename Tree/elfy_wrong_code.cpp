#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;


const int N = 1e5;
const int LOG = 20;
int n, q, T;
int depth[N+10], sub[N+10];
int up[N+10][LOG], bigchild[N+10];
vector<int> g[N+10];
int pos[N+10], chain[N+10];
ordered_set grab;
void dfs(int v, int p){
	up[v][0] = p;
	for(int i = 1;i < LOG; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	int big = -1; sub[v] = 1;
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
		sub[v]+= sub[to];
		if(big == -1 or sub[to] > sub[big]){
			big = to;
		}
	}
	bigchild[v] = big;
}
int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int k = depth[b]-depth[a];
	for(int i = 0;i < LOG; i++){
		if(k&(1<<i)) b = up[b][i];
	}
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}
void decompose(int v, int head){
	chain[v] = head, pos[v] = ++T;
	if(bigchild[v] != -1){
		decompose(bigchild[v], head);
	}
	for(int to : g[v]){
		if(to == up[v][0] or to == bigchild[v]) continue;
		decompose(to, to);
	}
}
int ans = 0;
int calc(int l, int r){
	if(l > r) swap(l,r);
	auto it = grab.lower_bound(l);
	auto it1 = grab.upper_bound(r);
	int L = grab.order_of_key(*it);
	int R = grab.order_of_key(*it1);
	return (R-L);
}
void query(int a, int b){
	while(chain[a] != chain[b]){
		if(depth[a] > depth[b]) swap(a, b);
		int l = pos[b], r = pos[chain[b]];
		ans+= calc(l,r);		
		b = up[chain[b]][0];
	}
	if(depth[a] > depth[b]) swap(a, b);
	int l = pos[b], r = pos[a];
	ans+= calc(l,r);		
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	decompose(1, 1);
	cin >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int v; cin >> v;
			if(grab.find(pos[v]) != grab.end()) grab.erase(pos[v]);
			else grab.insert(pos[v]);
		}else{
			int a, b; cin >> a >> b;
			int LCA = lca(a, b);
			query(a, LCA);
			query(LCA, b);
			cout << ans << '\n';
			ans = 0;
		}
	}
	return 0;
}

