#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;

struct node{
	node *l, *r;
	int sum;
	
	node(int x){
		l = nullptr, r = nullptr;
		sum = x;
	}	
	node(node *ll, node *rr){
		l = ll, r = rr;
		sum = 0;
		if(ll) sum+= ll->sum;
		if(rr) sum+= rr->sum;	
	};
};

typedef node* pnode;
int a[N+1], n, q, cnt = 1;
pnode version[N+1];


pnode build(int vl, int vr){
	if(vl == vr){
		return new node(a[vl]);
	}
	int mid = (vl + vr)>>1;
	return new node(build(vl, mid), build(mid+1,vr));
}

pnode update(pnode &t, int pos, int x, int vl, int vr){
	if(vl ==vr){
		return new node(x);
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos){
		return new node(update(t->l, pos, x, vl, mid), t->r);
	}else{
		return new node(t->l, update(t->r, pos, x, mid+1,vr));
	}
}



int get_sum(pnode &t, int l, int r, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return t->sum;
	}
	int mid = (vl + vr)>>1;
	return get_sum(t->l, l, r, vl, mid) + get_sum(t->r, l, r, mid+1, vr);
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	version[cnt] = build(1, n);
	cnt++;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int k, pos, x; cin >> k >> pos >> x;
			version[k] = update(version[k], pos, x, 1, n);
		}else if(type ==2){
			int k, l, r; cin >> k >> l >> r;
			cout << get_sum(version[k], l, r, 1, n) << '\n';
		}else{
			int k; cin >> k;
			version[cnt] = version[k];
			cnt++;
		}
	}
	return 0;
}

