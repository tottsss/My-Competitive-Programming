#include <bits/stdc++.h>
using namespace std;
//#define int long long
int compress = 500000;
const int N = 1000000;
int a[4*1000000], lazy[4 * 1000000];
struct node{
    int seg, pref, suf, sum, cnt;
};
vector<node>  tree(4*1000000);

void push(int v, int vl, int vr){
	if(lazy[v] == -1) return;
	int all = lazy[v]*(vr-vl+1);
	tree[v] = {all,all, all, all, lazy[v]};
	if(vl != vr){
		lazy[v*2+1] = lazy[v];
		lazy[v*2+2] = lazy[v];
	}
	lazy[v] = -1;
}

node combine(node a, int al, int ar,  node b, int bl, int br){
	node res;
	res.seg = max({a.seg, b.seg, a.suf + b.pref});
	res.cnt = a.cnt + b.cnt - (a.suf > 0 and b.pref > 0);
	res.sum = a.sum + b.sum;
	res.pref = a.pref;
	res.suf = b.suf;
	if(a.sum == (ar-al +1)) res.pref = a.sum + b.pref;
	if(b.sum == (br-bl+1)) res.suf = b.sum + a.suf;
	return res;
}
void build(int v, int vl, int vr){
	lazy[v] = -1;
    if(vl == vr){
        tree[v] = {0, 0, 0, 0, 0};
    }else{
        int mid = (vl + vr) / 2;
        build(2*v+1, vl, mid);
        build(2*v+2, mid+1, vr);
         tree[v] = combine(tree[2*v+1], vl, mid, tree[2*v+2], mid+1, vr);
    }
}

void update(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
   	if(l > vr or vl > r) return;
   	if(l <= vl and r >= vr){
   		lazy[v] = x;
		push(v, vl, vr);
		return;	
	}
    int mid = (vl + vr) / 2;
    update(l, r, x, v*2+1, vl, mid);
    update(l, r, x, v*2+2, mid+1, vr);
         tree[v] = combine(tree[2*v+1], vl, mid, tree[2*v+2], mid+1, vr);
}

node get(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
   	if(l > vr or vl > r) return {0, 0, 0, 0, 0};
   	if(l <= vl and r >= vr){
   		return tree[v];
	}
    int mid = (vl + vr) / 2;
    node L = get(l, r, v*2+1, vl, mid);
    node R = get(l, r, v*2+2, mid+1, vr);
    tree[v] = combine(tree[2*v+1], vl, mid, tree[2*v+2], mid+1, vr);
    return combine(L,vl, mid, R, mid+1, vr);
}

main(){
    ios::sync_with_stdio(0); 
	cin.tie(0);
    cout.tie(0); 
    int q; cin >> q;
    build(0, 0, N);
    while(q--){
    	char c; cin >> c;
    	int l, len;
    	cin >> l >> len;
    	int r = (l + len-1);
    	l+= compress;
		r+= compress;
		if(c == 'W') update(l, r, 0, 0, 0, N);
		else if(c == 'B') update(l, r, 1, 0, 0, N);
		cout << tree[0].cnt << ' ' << tree[0].sum << '\n';
	}
    return 0;
}