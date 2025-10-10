#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
int a[4*N];
pair<int, int> tree[4*N];
int n, q;

/*

Print operation l, r. Picks should write down the value of .
Modulo operation l, r, x. Picks should perform assignment a[i] = a[i] mod x for each i (l ≤ i ≤ r).
Set operation k, x. Picks should set the value of a[k] to x (in other words perform an assignment a[k] = x). 
*/
pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	return {a.ff + b.ff, max(a.ss, b.ss)};
}


void update(int l, int r, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = {x, x};
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= l) update(l, r, x, v<<1, vl, mid);
	else update(l, r, x, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

int get_sum(int l, int r, int v, int vl, int vr){
	if(vl > r or l > vr) return 0;
	if(l <= vl and r >= vr){
		return tree[v].ff;
	}
	int mid = (vl + vr)>>1;
	int L = get_sum(l, r, v<<1, vl, mid);
	int R = get_sum(l, r, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	return (L + R);
}

void modify(int l, int r, int mod,  int v, int vl, int vr){
	if(vl > r or l > vr) return;
	if(tree[v].ss < mod) return;
	if(vl == vr){
		tree[v].ff%= mod;
		tree[v].ss%= mod;
		return;
	}
	int mid = (vl + vr)>>1;
	modify(l, r, mod, v<<1, vl, mid);
	modify(l, r, mod, v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		update(i, i, a[i], 1, 1, n);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			cout << get_sum(l, r, 1, 1, n) << '\n';
		}else if(type == 2){
			int l, r, x; cin >> l >> r >> x;
			modify(l, r, x, 1, 1, n);
		}else{
			int pos, x; cin >> pos >> x;
			update(pos, pos, x, 1, 1, n);
		}
	}
	return 0;
}

