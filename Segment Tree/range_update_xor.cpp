#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;


int tree[20][4 * N + 1], lazy[20][4 * N + 1];
int n, a[N+1], q;




void build(int bit, int v, int vl, int vr){
	if(vl == vr){
		if(a[vl] & (1<<bit))  tree[bit][v] = 1;
//		tree[bit][v] = (a[vl] & (1<<bit));
		return;
	}
	int mid = (vl + vr)>>1;
	build(bit, v<<1, vl, mid);
	build(bit, v<<1|1, mid+1, vr);
	tree[bit][v] = tree[bit][v<<1] + tree[bit][v<<1|1];
}

void push(int bit, int v, int vl,int vr){
	if(lazy[bit][v] == 0) return;
	tree[bit][v] = (vr-vl+1) - tree[bit][v];
	if(vl != vr){
		lazy[bit][v<<1]^= lazy[bit][v];
		lazy[bit][v<<1|1]^= lazy[bit][v];
	}
	lazy[bit][v] = 0;
}

void update(int bit, int l, int r, int v, int vl, int vr){
	push(bit, v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[bit][v]^= 1;
		push(bit, v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(bit, l, r, v<<1, vl, mid);
	update(bit, l, r, v<<1|1, mid+1, vr);
	tree[bit][v] = tree[bit][v<<1] + tree[bit][v<<1|1];
}

int sum(int bit, int l, int r, int v, int vl, int vr){
	push(bit, v, vl, vr);
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr) return tree[bit][v];
	int mid = (vl + vr)>>1;
	return sum(bit, l, r, v<<1, vl, mid) + sum(bit, l, r, v<<1|1, mid+1, vr);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int bit = 0; bit < 20; bit++){
		build(bit, 1, 1, n);
	}
	cin >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			int s = 0;
			for(int bit = 0; bit < 20; bit++){
				s+= (1<<bit) * sum(bit, l, r, 1, 1, n);
			}
			cout << s << '\n';
		}else{
			int l, r, x; cin >> l >> r >> x;
			for(int bit = 0; bit < 20; bit++){
				if(x& (1<<bit)){
					update(bit, l, r, 1, 1, n);
				}
			}
		}
	}
	return 0;
}

