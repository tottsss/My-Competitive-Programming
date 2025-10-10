#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;


struct node{
	int vl, vr, sum, lazy;
	node *l, *r;
	node(){
		l = nullptr, r = nullptr;
		sum = 0, lazy = 0, vl = 1, vr = M;
	}	
	void extend(){
		if(l == nullptr){
			l = new node();
			r = new node();
			l->vl = vl, l->vr = (vl + vr)>>1;
			r->vl = ((vl + vr)>>1 )+ 1;
			r->vr = vr;
		}
	}
};
node*root;

void push(node *v){
	int vl = v->vl, vr = v->vr;
	if(!v or vl > vr or v->lazy == 0) return;
	v->sum+= (vr- vl + 1) * v->lazy;
	if(vl != vr){
		v->extend();
		v->r->lazy+= v->lazy;
		v->l->lazy+= v->lazy;
	}
	v->lazy = 0;
}


void update(int l, int r, int x, node*v){
	int vl = v->vl, vr = v->vr;
	push(v);
	if(vl > vr or vl > r or l > vr)return;
	if(l <= vl and r >= vr){
		v->lazy+= x;
		push(v); return;
	}
	v->extend();
	update(l, r, x, v->l);
	update(l, r, x, v->r);
	v->sum = (v->l->sum + v->r->sum);
}

int query(int l, int r, node*v){
	int vl = v->vl, vr = v->vr;
	push(v);
	if(vl > vr or vl > r or l > vr) return 0;
	if(l <= vl and r >= vr) return v->sum;
	v->extend();
	int L = query(l, r, v->l);
	int R = query(l, r, v->r);
	return (L +R);
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	root = new node();
	int n, q; cin >> n >> q;
	while(n--){
		// adding
		int l, r, x; cin >> l >> r >> x;
		update(l + 1, r, x, root);
	}
	while(q--){
		int l, r; cin >> l >> r;
		// sum in range
		cout << query(l + 1, r, root) << '\n';
	}
	return 0;
}

