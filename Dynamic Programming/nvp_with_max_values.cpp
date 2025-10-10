#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 2e5;
int n, h[N+5], val[N+5];
int tree[4*N];
void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	tree[v] = max(tree[v<<1], tree[v<<1|1]);
}

int get_max(int l, int r, int v, int vl, int vr){
	if(l > r) return 0;
	if(l > vr or vl > r) return INT_MIN;
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	return max(get_max(l, r, v<<1, vl, mid), get_max(l, r, v<<1|1, mid+1, vr));
}
//flowers atcoder dp contest
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> h[i];
	}
	for(int i = 1;i <= n; i++){
		cin >> val[i];
	}
	for(int i = 1;i <= n; i++){
		int mx = get_max(1, h[i]-1, 1, 1, n);
		update(h[i],val[i] + mx, 1, 1, n);
	}
	cout << get_max(1, n, 1, 1, n);
	return 0;
}

