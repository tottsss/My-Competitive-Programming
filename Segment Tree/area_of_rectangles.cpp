#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int COR = 1e6+1;
const int N = 2e6+1;
struct Q{
	int l, r, x;
};
vector<Q> upd[2*N+1];
pair<int, int> tree[4*N+5];
int lazy[4*N+5];
int n;
void push(int v, int vl, int vr){
	if(lazy[v] == 0) return;
	tree[v].ff += lazy[v];
	if(vl != vr){
		lazy[v<<1|1] += lazy[v];
		lazy[v<<1] += lazy[v];
	}
	lazy[v] = 0;
}


pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	if(a.ff > b.ff) return b;
	if(a.ff < b.ff) return a;
	return {a.ff, a.ss+b.ss};
}

void build(int v, int vl, int vr){
//	cout << 't';
	if(vl == vr){
		tree[v] = {0, 1};
	}else{
		int mid = (vl + vr)>>1;
		build(v<<1, vl, mid);
		build(v<<1|1, mid+1, vr);
		tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	}
}


void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v] += x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, x, v<<1, vl, mid);
	update(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

int get(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr){
		if(tree[v].ff == 0)return tree[v].ss;
		return 0;
	}
	int mid = (vl + vr)>>1;
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	return get(l, r, v<<1, vl, mid) + get(l, r, v<<1|1, mid+1,vr);
	
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		int x, l, x1, r; cin >> x >> l >> x1 >> r;
		x+= COR, l+= COR, r+= COR, x1+= COR;
		upd[x].push_back({l, r-1, 1});
		upd[x1].push_back({l, r-1, -1});
	}
	build(1, 1, N);
	/*
	Given n rectangles, your task is to determine the total area of their union.
	https://cses.fi/problemset/task/1741/
	
	*/
	long long area = 0;
	for(int X = 0; X <= N; X++){
		for(auto [l, r, x] : upd[X]){
//			cout << X << "  ==  ";
//			cout << l << ' ' << r << ' ' << x << '\n';
			update(l, r, x, 1, 1, N);
		}
		int s = get(1, N, 1, 1, N);
		if(s < 0) assert(false);
		area+= (N - s);
	}
	cout << area;
	return 0;
}

