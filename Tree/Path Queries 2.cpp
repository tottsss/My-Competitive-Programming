#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define int long long
const int N = 2e5+1;
 
int timer = 0, siz = 1;
 
vector<int> g[N], depth(N), sub(N, 1), chain(N), parent(N);
vector<int> bigchild(N,-1), pos(N), value(N), A(N);
vector<int> tree; 
void dfs(int v, int par){
	int mx = -1;
	for(auto to : g[v]){
		if(to == par) continue;
		depth[to] = depth[v]+1;
		parent[to] = v;
		/*
		for(int i = 1;i < LOG; i++){
			up[to][i] = up[up[to][i-1]][i-1];
		}
		*/
		dfs(to, v);
		sub[v]+= sub[to];
		if(sub[to] > mx){
			mx = sub[to];
			bigchild[v] = to;
		}
	}
	
}
 
 
void decompose(int v, int head, int par){
	pos[v] = timer++;
	chain[v] = head;
	if(bigchild[v]!=-1){
		decompose(bigchild[v], head, v);
	}
	for(auto to : g[v]){
		if(to == par or to == bigchild[v]) continue;
		decompose(to,to, v);
	}
}
 
int init(int n){
	while(n>siz) siz*= 2;
	tree.assign(2*siz-1, 0);
}
 
void build(int v, int vl, int vr){
	if(vl==vr){
		tree[v] = A[vl];
		return;
	}
	int mid =(vl+vr)/2;
	build(2*v+1, vl, mid);
	build(2*v+2, mid+1, vr);
	if(tree[2*v+1] > tree[2*v+2]) tree[v] = tree[2*v+1];
	else tree[v] = tree[2*v+2];
 	
}
 
int get_max(int l, int r, int v, int vl, int vr){
	if(l > vr or r < vl){
		return 0;
	}else if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr) / 2;
	int L = get_max(l, r, 2*v+1, vl,mid);
	int R = get_max(l, r, 2*v+2, mid+1, vr);
	if(L > R) return L;
	else return R;
	
}
void update(int p, int x, int v, int vl, int vr){
	if(vl==vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr) / 2;
	if(mid >= p){
		update(p, x, 2*v+1, vl, mid);
	}else{
		update(p, x, 2*v+2, mid+1, vr);
	}
	if(tree[2*v+1] > tree[2*v+2]) tree[v] = tree[2*v+1];
	else tree[v] = tree[2*v+2];
}
int query(int a, int b){
	int res = 0;
	for(; chain[a] != chain[b]; b = parent[chain[b]]){
		if(depth[chain[a]] > depth[chain[b]]) swap(a, b);
		res = max(res, get_max(pos[chain[b]], pos[b], 0, 0, siz));
	}
	if(depth[a] > depth[b]) swap(a, b);
	res = max(res, get_max(pos[a], pos[b], 0, 0, siz));
	return res;
}
 
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 int n; cin >> n;
	 int Q; cin >> Q;
	 for(int i = 1;i <= n; i++){
		 cin >> value[i];
	 }
	 for(int i = 0;i < n-1; i++){
		 int a, b; cin >> a >> b;
		 g[a].push_back(b);
		 g[b].push_back(a);
	 }
	 depth[1] = 0; parent[1] = 1;
	 dfs(1, -1);
	 decompose(1, 1, -1);
	 for(int i = 1;i <= n; i++){
		 A[pos[i]] = value[i];
	 }
	 init(n);
	 build(0,0, siz);
	 while(Q--){
		 int type; cin >> type;
		 if(type==1){
			 int change, x; cin >> change >> x;
			 value[change] = x;
			 A[pos[change]] = value[change];
			 update(pos[change], x, 0, 0, siz);
		 }else{
			 int u, v; cin >> u >> v;
			 cout << query(u, v) << " ";
		 }
	 }
	return 0;
}