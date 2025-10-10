#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5;
int n, a[4*N],tree[4*N];
pair<int, int> lazy[4*N];

void build(int v, int vl, int vr){
	lazy[v] = {0, 0};
	if(vl == vr){
		if(vl > n) tree[v] = LLONG_MAX;
		else tree[v] = a[vl];
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = min(tree[v<<1], tree[v<<1|1]);
}
// lazy[v].second == 1 (update)
// lazy[v].second == 2 (adding)
void push(int v, int vl, int vr){
	if(lazy[v].second == 0) return;
	if(lazy[v].second == 2){
		tree[v] += lazy[v].first;
		if(vl != vr){
			lazy[v<<1].first += lazy[v].first;
			lazy[v<<1|1].first += lazy[v].first;
			if(lazy[v<<1].second == 0) lazy[v<<1].second = 2;
			if(lazy[v<<1|1].second == 0) lazy[v<<1|1].second = 2;
		}
	}else{
		tree[v] = lazy[v].first;
		if(vl != vr){
			lazy[v<<1] = lazy[v];
			lazy[v<<1|1] = lazy[v];
		}
	}
	lazy[v] = {0, 0};
}

void add(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		if(lazy[v].second == 0) lazy[v].second = 2;
		lazy[v].first+= x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(l, r, x, v<<1, vl, mid);
	add(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = min(tree[v<<1], tree[v<<1|1]);
}

void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v] = {x, 1};
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, x, v<<1, vl, mid);
	update(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = min(tree[v<<1], tree[v<<1|1]);
}


int get_min(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return LLONG_MAX;
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	int L = get_min(l, r, v<<1, vl, mid);
	int R = get_min(l, r, v<<1|1, mid+1, vr);
	tree[v] = min(tree[v<<1], tree[v<<1|1]);
	return min(L,R);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	string q; 
	while(cin >> q){
		if(q[0] == 'm'){
			int i, j; cin >> i >> j;
			cout << get_min(i, j, 1, 1, n) << '\n';
		}else{
			int l, r, x; cin >> l >> r >> x;
			if(q[0] == 'a'){
				add(l, r, x, 1, 1, n);
			}else{
				update(l, r, x, 1, 1, n);
			}
		}
	}
	return 0;
}

