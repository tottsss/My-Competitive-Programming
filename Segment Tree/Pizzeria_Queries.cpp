#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int  a[4 * N], tree[4 * N], tree1[4*N];
int n, q;
void build(int v, int vl, int vr){
	if(vl == vr){
		if(vl > n){
			tree[v] = INT_MAX;
			tree1[v] = INT_MAX;
		} else{
			tree[v] = a[vl] + vl;
			tree1[v] = a[vl] - vl;
		} 
	}else{
		int mid = (vl + vr)>>1;
		build(v<<1, vl, mid);
		build(v<<1|1, mid+1, vr);
		tree[v] = min(tree[v<<1],tree[v<<1|1]);
		tree1[v] = min(tree1[v<<1],tree1[v<<1|1]);
	}
}


void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		a[vl] = x;
		tree[v] = a[vl] + vl;
		tree1[v] = a[vl] - vl;
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos){
			update(pos, x, v<<1, vl, mid);
		}else{
			update(pos, x, v<<1|1, mid+1, vr);
		}
		tree[v] = min(tree[v<<1],tree[v<<1|1]);
		tree1[v] = min(tree1[v<<1],tree1[v<<1|1]);
	}
}

int query(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return INT_MAX;
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	int L = query(l, r, v<<1, vl, mid);
	int R = query(l, r, v<<1|1, mid+1, vr);
	return min(L, R);
}
int query1(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return INT_MAX;
	if(l <= vl and r >= vr) return tree1[v];
	int mid = (vl + vr)>>1;
	int L = query1(l, r, v<<1, vl, mid);
	int R = query1(l, r, v<<1|1, mid+1, vr);
	return min(L, R);
}

main(){
   	cin >> n >> q;
   	for(int i = 1;i <= n; i++){
   		cin >> a[i];
	}
	build(1, 1, n);
	while(q--){
		int type; cin >> type;
		if(type == 2){
			int pos; cin >> pos;
			// buying
			int up = query(pos, n, 1, 1, n);
			int down = query1(1, pos, 1, 1, n);
			up-= pos; down+= pos;
			cout << min(up, down) << '\n';
		}else{
			int pos, x; cin >> pos >> x;
			// update
			update(pos, x, 1, 1, n);
		}
	}
	return 0;
}

