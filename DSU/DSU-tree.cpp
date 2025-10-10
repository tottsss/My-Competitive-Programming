#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 6e5;
int par[N], c[N];
int tin[N], tout[N], T;
vector<int> g[N];
int deleted[N];
int n, m, q;
vector<pair<int, int> > edge, query;
void dfs(int v){
//	cout << v << ' ';
	tin[v] = ++T;
	for(int to : g[v]){
		dfs(to);
	}
//	cout << v << ' ';
	tout[v] = T;
}


int find_set(int v){
	return par[v] = (par[v]==v ? v : find_set(par[v]));
}
void union_set(int a, int b){
	a = find_set(a), b = find_set(b);
	if(a == b) return;
	n++;
	par[n] = n;
	g[n].push_back(a);
	par[a] = par[b] = n;
	g[n].push_back(b);
}
pair<int, int> tree[4*N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	if(a.ff>b.ff) return a;
	return b;
}

void update(int pos, pair<int, int> x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

pair<int, int> get_max(int l, int r, int v, int vl, int vr){
	if(l > r) assert(false);
	if(l > vr or vl > r) return {0,0};
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	return combine(get_max(l, r, v<<1, vl, mid), get_max(l, r, v<<1|1, mid+1, vr));
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i <= n; i++){
		par[i] = i;
		cin >> c[i];
	}
	edge.push_back({0, 0});
	query.push_back({0, 0});
	for(int i = 1;i <= m; i++){
		int a, b; cin >> a >> b;
		edge.push_back({a, b});
	}
	for(int i = 1;i <= q; i++){
		int type, v; cin >> type >> v;
		query.push_back({type, v});
		if(type == 2) deleted[v]=1;
	}
	for(int i = 1;i <= m; i++){
		if(deleted[i]==0){
//			cout << edge[i].ff << ' ' << edge[i].ss << '\n';
			union_set(edge[i].ff, edge[i].ss);
		}
	}
	for(int i = q;i >= 1; i--){
		int type = query[i].ff, v = query[i].ss;
		if(type == 1){
//			cout << v << " = " << find_set(v) << '\n';
			query[i].ss = find_set(v);
		}else{
			union_set(edge[v].ff, edge[v].ss);
		}
	}
	for(int i = 1;i <= n; i++){
		if(par[i] == i){
			dfs(i);
		}
	}
	// https://codeforces.com/contest/1416/problem/D
//	cout << '\n';
//	for(int i = 1;i <= n; i++){
//		cout << i << " = " << tin[i] << ' ' << tout[i] << '\n';
//	}
	for(int i = 1;i <= n; i++){
		update(tin[i], make_pair(c[i], tin[i]), 1, 1, n);
	}
	for(int i = 1;i <= q; i++){
		if(query[i].ff == 1){
			int v = query[i].ss;
//			cout << v << " = " << tin[v] << ' ' << tout[v]  << ' ';
			pair<int, int> C = get_max(tin[v], tout[v], 1, 1, n);
			cout << C.ff << '\n';
			if(C.ff != 0)
			update(C.ss, {0, 0}, 1, 1, n);
		}
	}
	

	return 0;
}

