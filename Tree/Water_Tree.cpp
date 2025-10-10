#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 500000;
vector<int> g[N+1];
int sub[N+1], depth[N+1], tin[N+1], tout[N+1];

int parent[N+1], bigchild[N+1], chain[N+1], post[N+1];
int n, q, T;
void dfs(int v, int p){
	tin[v] = ++T, sub[v] = 1;
	bigchild[v] = -1;
	parent[v] = p;
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
		if(bigchild[v] == -1 or sub[bigchild[v]] < sub[to]) bigchild[v] = to;
		sub[v]+= sub[to];
	}
	tout[v] = ++T;
}
int tree[4*N], lazy[4*N];
void push(int v, int vl, int vr){
	if(lazy[v] == -1) return;
	tree[v] = (vr-vl+1)*lazy[v];
	if(vl != vr){
		lazy[v<<1] = lazy[v];
		lazy[v<<1|1] = lazy[v];
	}
	lazy[v] = -1;
}
void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl,vr);
	if(l > r) swap(l,r);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v] = x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, x, v<<1, vl, mid);
	update(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = (tree[v<<1] + tree[v<<1|1]);
}
int get(int pos, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl == vr) return tree[v];
	int mid = (vl + vr)>>1;
	if(mid >= pos) return get(pos, v<<1, vl, mid);
	else return get(pos, v<<1|1, mid+1, vr);
}
void decompose(int v, int head){
	chain[v] = head; post[v] = ++T;
	if(bigchild[v] != -1) decompose(bigchild[v], head);
	for(int to : g[v]){
		if(to == parent[v] or to == bigchild[v]) continue;
		decompose(to, to);
	}
}
void query(int a, int b){
	while(chain[a] != chain[b]){
		if(depth[a] > depth[b]) swap(a,b);
		update(post[b], post[chain[b]], 0, 1, 1, n);
		b = parent[chain[b]];
	}
	if(depth[a] > depth[b]) swap(a,b);
	update(post[a], post[b], 0, 1, 1, n);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < 4*N; i++) lazy[i] = -1;
	dfs(1, 1);
	T = 0;
	decompose(1, 1);
	cin >> q;
	while(q--){
		int c, v; cin >> c >> v;
		if(c == 1){
			int l = post[v];
			int r = post[v]+sub[v]-1;
			update(l, r, 1, 1, 1, n);
		}else if(c == 2){
			query(1, v);
		}else{
			cout << get(post[v], 1, 1, n) << '\n';
		}
	}
	return 0;
}

