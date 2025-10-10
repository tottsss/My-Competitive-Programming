#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int LOG = 20;
int up[N+1][LOG+1], depth[N+1];
int tin[N+1], tout[N+1];
int bigchild[N+1], chain[N+1], pos[N];
int sub[N+1];
vector<pair<int, int> > g[N+1];
int n, q, T, position;
#define int long long
int val[N+1];
void dfs(int v, int p){
	tin[v] = ++T;
	up[v][0] = p;
	for(int j = 1;j < LOG; j++) up[v][j] = up[up[v][j-1]][j-1];
	sub[v] = 1;
	int big=-1;
	for(auto [to, w] : g[v]){
		if(to != p){
			depth[to] = depth[v]+1;
			val[to] = w;
			dfs(to, v);
			sub[v]+= sub[to];
			if(big == -1 or sub[big] < sub[to]){
				big = to;
			}
		}
	}
	tout[v] = ++T;
	bigchild[v] = big;
}
int isAnc(int v, int p){
	return (tin[p] <= tin[v] and tout[v] <= tout[p]);
}

void decompose(int v, int head){
	pos[v] = ++position;
	chain[v] = head;
	if(bigchild[v] != -1){
		decompose(bigchild[v], head);
	}
	for(int to : g[v]){
		if(to == up[v][0] or to == bigchild[v]) continue;
		decompose(to, to);
	}
}
int tree[4*N]

void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}
void add(int l, int r,int x, int v, int vl, int vr){
	if(l > r) swap(l,r);
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v]+= x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(l, r, x, v<<1, vl, mid);
	add(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = (tree[v<<1] + tree[v<<1|1]);
}
int get(int pos, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl == vr) return tree[v];
	int mid = (vl + vr)>>1;
	if(mid >= pos) return get(pos, v<<1, vl, mid);
	else return get(pos, v<<1|1, mid+1, vr); 
}
void query(int a, int b, int x){
	for(; chain[a] != chain[b]; ){
		if(depth[b] < depth[a]) swap(a, b);
		add(pos[b], pos[chain[b]], x, 1, 1, n);
		b = up[chain[b]][0];
	}	
	if(depth[b] < depth[a]) swap(a, b);
	add(pos[a], pos[b], x,  1, 1, n);
}

int lca(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	int k =depth[b]-depth[a];
	for(int i = 0;i < LOG; i++){
		if(k&(1LL<<i)){
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		int w; cin >> w;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	decompose(1, 1);
	cin >> q;
	while(q--){
		
	}
	return 0;
}