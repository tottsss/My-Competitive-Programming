#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5e5;

int a[N + 1];
int n, q;

struct node{
	int mx = 0, sum = 0, mn = 0;
};
node tree[4 * N + 1];
int lazy[4*N+1];
node combine(node a, node b){
	return {max(a.mx, b.mx), a.sum + b.sum, min(a.mn, b.mn)};
}

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = {a[vl], a[vl], a[vl]};
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

void push(int v, int vl, int vr){
	if(lazy[v] == -1) return;
	tree[v] = {lazy[v], lazy[v] * (vr-vl+1), lazy[v]};
	if(vl != vr){
		lazy[v<<1] = lazy[v];
		lazy[v<<1|1] = lazy[v];
	}
	lazy[v] = -1;
}

void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v] = x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, x, v<<1, vl, mid);
	update(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

void divide(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		if(tree[v].mx < x){
			update(vl, vr, 0, 1, 1, n);
			return;
		}
		if(tree[v].mx == tree[v].mn){
			update(vl, vr, tree[v].mx / x, 1, 1, n);
			return;
		}
	}
	if(vl == vr){
		tree[v] = {tree[v].mx / x, tree[v].mx / x, tree[v].mx / x};
		return;
	}
	int mid = (vl + vr)>>1;
	divide(l, r, x, v<<1, vl, mid);
	divide(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

int get_sum(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr) return tree[v].sum;
	int mid = (vl + vr)>>1;
	return get_sum(l, r, v<<1, vl, mid) + get_sum(l, r, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0;i <= 4 * n; i++) lazy[i] = -1;
	build(1, 1, n);
	while(q--){
//		https://atcoder.jp/contests/abc256/tasks/abc256_h
		int type; cin >> type;
		if(type == 1){
			int l, r, x; cin >> l >> r >> x;
			divide(l, r, x, 1, 1, n);
		}else if(type == 2){
			int l, r, x; cin >> l >> r >> x;
			update(l, r, x, 1, 1, n);
		}else{
			int l, r; cin >> l >> r;
			cout << get_sum(l, r, 1, 1, n) << '\n';
		}
	}
	return 0;
}

