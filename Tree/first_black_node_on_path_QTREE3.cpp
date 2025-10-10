#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 100000;
int n, q;
vector<int> g[N+1];
int sub[N+1], depth[N+1], parent[N+1], bigchild[N+1];
int pos[N+1], chain[N+1], where[N+1];
int T;

void dfs(int v, int p){
	parent[v] = p;
	bigchild[v] = -1, sub[v] = 1;
	for(int to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
		sub[v]+= sub[to];
		if(bigchild[v] == -1 or sub[bigchild[v]] < sub[to]){
			bigchild[v] = to;
		}
	}
}

void decompose(int v, int head){
	chain[v] = head, pos[v] = ++T;
	where[T] = v;
	if(bigchild[v]!=-1){
		decompose(bigchild[v], head);
	}
	for(int to : g[v]){
		if(to==parent[v] or to == bigchild[v]) continue;
		decompose(to, to);
	}
}
pair<int, int> tree[4*N];


pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	if(a.ff) return {a.ff+b.ff, a.ss};
	return {a.ff+b.ff,b.ss};
}

void update(int pos, int v, int vl, int vr){
	if(vl == vr){
		tree[v].ff^= 1;
		tree[v].ss = vl;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, v<<1, vl, mid);
	else update(pos, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1],tree[v<<1|1]);
}

pair<int, int> get_k(int l, int r, int k, int v, int vl, int vr){
	if(l > vr or vl > r) return {0,0};
	if(l<= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	 return combine(get_k(l, r, k, v<<1, vl, mid), get_k(l, r, k, v<<1|1, mid+1, vr));
}


void query(int a, int b, int k){
	pair<int, int> ans = {0,-1};
	while(chain[a] != chain[b]){
		pair<int, int> G = get_k(pos[chain[b]], pos[b],1, 1, 1, n);
		ans = combine(G, ans);
		b = parent[chain[b]];
	}
	pair<int, int> G = get_k(pos[a], pos[b],1, 1, 1, n);
	ans = combine(G, ans);
	if(ans.ff==0) cout << -1;
	else
	cout << where[ans.ss];
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   /*
   
    0 i : change the color of the i-th node (from white to black, or from black to white);
    or
    1 v : ask for the id of the first black node on the path from node 1 to node v. if it doesn't exist, you may return -1 as its result. 
   SPOJ QTREE3 - Query on a tree again!
   */
	cin >> n >> q;
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	decompose(1, 1);
	while(q--){
		int c, v; cin >> c >> v;
		if(c == 0){
			update(pos[v], 1, 1, n);
		}else{
			query(1, v, 1); cout << '\n';
		}
	}
	return 0;
}

