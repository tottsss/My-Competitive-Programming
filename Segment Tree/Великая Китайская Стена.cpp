#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;

struct info{
	int mn, mx, idx;
};
info tree[4*N];
int a[4*N], lazy[4*N];
int n, q;

info combine(info a, info b){
	info res;
	res.mx = max(a.mx, b.mx);
	if(a.mn < b.mn) res.idx = a.idx, res.mn = a.mn;
	else res.idx = b.idx, res.mn = b.mn;
	return res;
}
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = {0, 0, vl};
		return;
	}
	int mid =(vl + vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}


void push(int v, int vl, int vr){
	if(lazy[v] ==0) return;
	tree[v] = {lazy[v], lazy[v], tree[v].idx};
	if(vl != vr){
		lazy[v<<1] = lazy[v];
		lazy[v<<1|1] =  lazy[v];
	}
	lazy[v] = 0;
}

void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return;
	if(l <= vl and r >= vr){
		lazy[v] = x;
		push(v, vl, vr);
		return;
	}
	int mid =(vl + vr)>>1;
	update(l, r, x, v<<1, vl, mid);
	update(l, r, x, v<<1|1 , mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

info get_min(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return {INT_MAX, INT_MIN, 0};
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid =(vl + vr)>>1;
	info L = get_min(l, r,  v<<1, vl, mid);
	info R = get_min(l, r, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	return combine(L, R);
}

void defend(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return;
	if(tree[v].mn >= x){
		return;
	}
	if(tree[v].mx < x){
		update(l, r, x, v, vl, vr);
		return;
	}
	if(vl == vr){
		tree[v] = {max(x, tree[v].mn), max(x, tree[v].mx), tree[v].idx};
		return;
	}
	int mid = (vl + vr)>>1;
	defend(l, r, x, v<<1, vl, mid);
	defend(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	build(1, 1, n);
	while(q--){
		string type; cin >> type;
		if(type[0] == 'd'){
			int l, r, x; cin >> l >> r >> x;
			defend(l, r, x, 1, 1, n);
		}else{
			int l, r; cin >> l >> r;
			info res = get_min(l, r, 1, 1, n);
			cout << res.mn << " " << res.idx << '\n';
		}
	}
	return 0;
}

