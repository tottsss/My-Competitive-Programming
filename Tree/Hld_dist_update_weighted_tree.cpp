#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int LOG = 20;
int up[N+1][LOG+1], depth[N+1];
int tin[N+1], tout[N+1];
int bigchild[N+1], chain[N+1], pos[N];
int sub[N+1];
vector<pair<int, int> > g[N+1];
vector<pair<pair<int, int>, int> > edge;
int n, q, T, position;
int val[N+1], A[N+1];
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
	for(auto [to, w] : g[v]){
		if(to == up[v][0] or to == bigchild[v]) continue;
		decompose(to, to);
	}
}
int tree[4*N];


void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = A[vl];
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}

void update(int po, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= po) update(po, x, v<<1, vl, mid);
	else update(po, x, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}

int sum(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	return sum(l, r, v<<1, vl, mid) + sum(l, r, v<<1|1, mid+1, vr);
}

int query(int a, int b){
	int s = 0;
	for(; chain[a] != chain[b]; ){
		if(depth[b] < depth[a]) swap(a, b);
		s+= sum(min(pos[b], pos[chain[b]]), max(pos[b], pos[chain[b]]), 1, 1, n);
		b = up[chain[b]][0];
	}	
	if(depth[b] < depth[a]) swap(a, b);
	s+= sum(min(pos[a], pos[b]), max(pos[a], pos[b]), 1, 1, n);
	return s;
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
		edge.push_back({{a, b}, w});
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	dfs(1, 1);
	decompose(1, 1);
	for(int i = 1;i <= n; i++){
//		cout << i << " = " << pos[i] << '\n';
		A[pos[i]] = val[i];
//		update(pos[i], val[i], 1, 1, n);
	}
	build(1, 1, n);
	cin >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int po, w; cin >> po >> w;
			int a = edge[po-1].ff.ff;
			int b = edge[po-1].ff.ss;
			if(isAnc(a, b)){
				val[a] = w;
				A[pos[a]] = w;
				update(pos[a], w, 1, 1, n);
			}else{
				val[b] = w;
				A[pos[b]] = w;
				update(pos[b], w, 1, 1, n);
			}
		}else{
			int u, v; cin >> u >> v;
			int lc = lca(u, v);
			int dist = query(u, lc) + query(v, lc);
			dist-= 2*val[lc];
//			cout << lc << " = ";
			cout << dist << '\n';
		}
	}
	return 0;
}