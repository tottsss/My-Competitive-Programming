#include <bits/stdc++.h>
using namespace std;
int n, q; 
const int N = 2e5;
const int LOG = 20;
int up[N + 10][LOG + 5], tree[4*N];
int chain[N+10], val[N+10], sub[N+10], depth[N+10], pos[N+10];
int bigchild[N+10], parent[N+10], A[N+10];
vector<int> g[N+10];
int mx, timer = 1;
 
 int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--){
        if((k & (1<<i) )){
            a = up[a][i];
        }
    }
    if(a == b) return a;
    for(int i = LOG-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
 
void dfs(int v, int par){
    up[v][0] = par;
    for(int i = 1;i < LOG; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
	mx = -1;
	sub[v] = 1;
	bigchild[v] = -1;
	for(auto to : g[v]){
		if(to == par) continue;
		depth[to] = depth[v] + 1;
		parent[to] = v;
		dfs(to, v);
		sub[v]+= sub[to];
		if(mx <sub[to]){
			mx = sub[to];
			bigchild[v] = to;
		}
	}
}
 
void decompose(int v, int head, int par){
	chain[v] = head;
	pos[v] = timer++;
	if(bigchild[v] != -1){
		decompose(bigchild[v], head, v);
	}
	for(auto to : g[v]){
		if(to == par or to == bigchild[v]) continue;
		decompose(to, to, v);
	}
}
 
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = A[vl];
		return;
	}
	int mid = (vl + vr) / 2;
	build(2*v, vl, mid); 
	build(2*v+1, mid+1, vr);
	tree[v] = max(tree[2*v],tree[2*v+1]);
}
 
void update(int ind, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr) / 2;
	if(mid>= ind){
		update(ind, x, 2*v, vl, mid);
	}else update(ind, x, 2*v+1, mid+1, vr);
	tree[v] = max(tree[2*v], tree[2*v+1]);
}
 
int get(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return INT_MIN;
	if(l<= vl and r >= vr) return tree[v];
	int mid = (vl +vr)/2;
	int L = get(l, r, 2*v, vl, mid);
	int R = get(l, r, 2*v+1, mid+1, vr);
	return max(L,R);
}
 
int query(int a, int b){
	int res = INT_MIN;
	while(chain[a] != chain[b]){
		cout << 't';
		if(depth[chain[a]] > depth[chain[b]]) swap(a, b);
		res = max(res, get(pos[chain[b]], pos[b], 1, 1, n));
		b = parent[chain[b]];
	}
	if(depth[a] > depth[b]) swap(a, b);
	res = max(res, get(pos[a], pos[b], 1, 1, n));
	return res;
}
 
main(){
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> val[i];
	}	
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	parent[1] = 1;
	dfs(1, 1);
	decompose(1, 1, 1);
	for(int i = 1;i <= n; i++){
		A[pos[i]] = val[i];
	}
	build(1, 1, n);
	while(q--){
		int type; cin >> type;
		 if(type==1){
			 int change, x; cin >> change >> x;
			 val[change] = x;
			 A[pos[change]] = val[change];
			 update(pos[change], x, 1, 1, n);
		 }else{
			 int u, v; cin >> u >> v;
			 int lc = lca(u, v);
			 cout << max(query(u, lc), query(v, lc)) << " ";
		 }
	}
	return 0;
}