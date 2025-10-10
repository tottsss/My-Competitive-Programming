#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5;
// if Ai? is 0, replace it with S; 
//if Ai? is 1, replace it with T; 
//if Ai? is 2, replace it with U.
struct node{
	int cnt[3][3];
};
int n, q;
struct laz{
	int s, t, u;
};
vector< laz> lazy(1<<20);
node tree[(1<<20)];
int a[(1<<20)];
node none;
node merge(node a, node b){
	node res = none;
	res.cnt[0][0] = a.cnt[0][0] + b.cnt[0][0];
	res.cnt[1][1] = a.cnt[1][1] + b.cnt[1][1];
	res.cnt[2][2] = a.cnt[2][2] + b.cnt[2][2];	
	res.cnt[1][0] = a.cnt[1][0] + b.cnt[1][0];
	res.cnt[2][0] = a.cnt[2][0] + b.cnt[2][0];
	res.cnt[2][1] = a.cnt[2][1] + b.cnt[2][1];
	
	res.cnt[1][0]+=(a.cnt[1][1] * b.cnt[0][0]);
	res.cnt[2][1]+=(a.cnt[2][2] * b.cnt[1][1]);
	res.cnt[2][0]+=(a.cnt[2][2] * b.cnt[0][0]);
	return res;
}

node create(node A, int s, int t, int u){
	node res = none;
	res.cnt[s][s] = A.cnt[0][0];
	res.cnt[t][t] = A.cnt[1][1];
	res.cnt[u][u] = A.cnt[2][2]; 
	res.cnt[s][t] = A.cnt[0][1];
	res.cnt[t][s] = A.cnt[1][0];
	res.cnt[t][u] = A.cnt[1][2];
	res.cnt[u][t] = A.cnt[2][1];
	res.cnt[u][s] = A.cnt[2][0];
	res.cnt[s][u] = A.cnt[0][2];
	return res;
}

void push(int v, int vl, int vr){
	if(lazy[v].s == -1) return;
	tree[v] = create(tree[v], lazy[v].s, lazy[v].t, lazy[v].u);
	if(vl != vr){
		lazy[v<<1|1] = lazy[v];
		lazy[v+v+2] = lazy[v];
	}
	lazy[v] = {-1, -1, -1};
}

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = none;
		if(vl >= n) assert(false);
		if(vl < n) tree[v].cnt[a[vl]][a[vl]] = 1;
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1|1, vl, mid);
	build(v*2+2, mid+1, vr);
	tree[v] = merge(tree[v<<1|1], tree[v*2 + 2]);
}


node query(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return none;
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	node L = query(l, r, v<<1|1, vl, mid);
	node R = query(l, r, v+v+2, mid+1, vr);
	tree[v] = merge(tree[v<<1|1],tree[v+v+2]);
	return merge(L,R);
}

void update(int l, int r, int s, int t, int u, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return;
	if(l <= vl and r >= vr){
		lazy[v] = {s, t, u};
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, s, t, u, v<<1|1, vl, mid);
	update(l, r, s, t, u, v+v+2, mid+1, vr);
	tree[v] = merge(tree[v<<1|1], tree[v+v+2]);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	lazy.assign((1<<19), {-1, -1, -1});
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	build(0, 0, n-1);
//	cout << tree[0].inver << '\n';
	while(q--){
		int type; cin >> type;
		int l, r; cin >> l >> r;
		l--, r--;
		if(type == 1){
			node Answer = query(l, r, 0, 0, n-1);
			cout << Answer.cnt[1][0] + Answer.cnt[2][0] + Answer.cnt[2][1] << '\n';
		}else{
			int s, t, u; cin >> s >> t >> u;
			update(l, r, s, t, u, 0, 0, n-1);
		}
	}

	return 0;
}

