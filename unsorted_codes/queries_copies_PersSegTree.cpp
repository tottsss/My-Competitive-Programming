#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e6;
int a[(int)2e5+1], n, q, cnt = 1, emp = 0;
int version[(int)2e5+1];
long long tree[N]; int Left[N], Right[N];
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = a[vl];
		return;
	}
	Left[v] = emp++;
	Right[v] = emp++;
	int mid = (vl + vr)>>1;
	build(Left[v], vl, mid);
	build(Right[v], mid+1, vr);
	tree[v] = (tree[Left[v]] + tree[Right[v]]);
}

int update(int pos, int x, int v, int vl, int vr){
	if(pos < vl or pos > vr) return v;
	int NEW = emp++;
	if(vl == vr){
		tree[NEW] = x;
		return NEW;
	}
	int mid = (vl + vr)>>1;
	Left[NEW] = update(pos, x, Left[v], vl, mid);
	Right[NEW] = update(pos, x, Right[v], mid+1, vr);
	tree[NEW] = (tree[Left[NEW]] + tree[Right[NEW]]);
	return NEW;
}
 
 
long long get_sum(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	return get_sum(l, r, Left[v], vl, mid) + get_sum(l, r, Right[v], mid+1, vr);
} 
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	version[cnt] = emp++;
	build(version[1], 1, n);
	cnt++;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int k, pos, x; cin >> k >> pos >> x;
			version[k] = update(pos, x,version[k], 1, n);
		}else if(type ==2){
			int k, l, r; cin >> k >> l >> r;
			cout << get_sum(l, r,version[k], 1, n) << '\n';
		}else{
			int k; cin >> k;
			version[cnt] = version[k];
			cnt++;
		}
	}
	return 0;
}