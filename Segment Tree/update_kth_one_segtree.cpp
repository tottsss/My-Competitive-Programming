#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 100000;

int n, q;
int tree[4*N+100], lazy[4*N+100];


void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 0;
	}else{
		int mid = (vl + vr)>>1;
		build(v<<1, vl, mid);
		build(v<<1|1, mid+1, vr);
		tree[v] = tree[v<<1] + tree[v<<1|1];
	}
}


void push(int v, int vl, int vr){
	if(lazy[v] == 0) return;
	tree[v] = (vr-vl+1) - tree[v];
	if(vl != vr){
		lazy[v<<1]^= 1;
		lazy[v<<1|1]^= 1;
	}
	lazy[v] = 0;
}

void update(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;;
	if(l <= vl and r >= vr){
		lazy[v]^= 1;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(l, r, v<<1, vl, mid);
	update(l, r, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}

int k_th(int k, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl == vr){
		return vl;
	}
	int mid = (vl + vr)>>1;
	push(v<<1, vl, mid);
	push(v<<1|1, mid+1, vr);
	if(tree[v<<1] >= k){
		return k_th(k, v<<1, vl, mid);
	}
	return k_th(k - tree[v<<1], v<<1|1, mid+1, vr);
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			update(l+1, r, 1, 1, n);
		}else{
			int k; cin >> k;
			cout << k_th(k+1, 1, 1, n)-1 << '\n';
		}
	}

	return 0;
}

