#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5+1;

vector<int> tree[(1<<20)];
int a[(1<<20)], n, q;

void build(int v, int vl, int vr){
	if(vl == vr){
		int New = 0;
		if(vl < n) New = a[vl];
		tree[v] = vector<int>(1, New);
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1|1, vl, mid);
	build((v<<1) + 2, mid+1, vr);
	merge(all(tree[v<<1|1]), all(tree[(v<<1) + 2]), back_inserter(tree[v]));
}

int query(int l, int r, int x, int v, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		int L = upper_bound(all(tree[v]), x) - tree[v].begin();
		return L;
	}
	int mid = (vl + vr)>>1;
	int A = query(l, r, x, v<<1|1, vl, mid);
	int B = query(l, r, x, (v<<1) + 2, mid+1, vr);
	return A+B;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	build(0, 0, n-1);
	while(q--){
		int L, R, K; cin >> L >> R >> K;
		int l = (int)-1e9 - 1, r = (int)1e9 + 1;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(query(L-1, R-1, mid, 0, 0, n-1) >= K) r = mid;
			else l = mid;
		}
		cout << r << "\n";
	}
	return 0;
}

