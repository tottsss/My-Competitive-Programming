#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int tree[4*N], a[N];
int n;
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 1;
		return;
	}
	int mid = (vl + vr)/2;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}
int find_k(int k, int v, int vl, int vr){
	if(vl == vr) return vl;
	int mid = (vl + vr)>>1;
	if(tree[v<<1] > k){
		return find_k(k, v<<1, vl, mid);
	}else return find_k(k-tree[v<<1], v<<1|1, mid+1, vr);
}
void update(int pos, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 0;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, v<<1, vl, mid);
	else update(pos, v<<1|1, mid+1, vr);
    tree[v] = tree[v<<1] + tree[v<<1|1];
}
main(){
	cin >> n; 
	for(int i = 1;i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for(int i = 1;i <= n; i++){
		int k; cin >> k;k--;
		int pos = find_k(k, 1, 1, n);
		update(pos, 1, 1, n);
		cout << a[pos] << ' ';
	}
	return 0;
}