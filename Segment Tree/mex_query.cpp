#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int a[N+10], b[N+10], n, q, ans[N+10];
vector< pair<int, int> > Right[N+10];
int t[4*N];
int update(int pos,int x, int v, int vl, int vr){
	if(vl == vr) t[v] = x;
	else{
		int mid = (vl + vr)>>1;
		if(mid >= pos) update(pos, x, v<<1, vl, mid);
		else update(pos, x, v<<1|1, mid+1, vr);
		t[v] = min(t[v<<1], t[v<<1|1]);
	}
}

int find(int x, int v, int vl, int vr){
	if(vl == vr) return vl;
	int mid = (vl + vr)>>1;
	if(x > t[v<<1]){
		return find(x, v<<1, vl, mid);
	}else return find(x, v<<1|1, mid+1, vr);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		cin >> b[i];
	}
	cin >> q;
	for(int i = 0;i < q; i++){
		int l, r; cin >> l >> r;
		Right[r].push_back({l, i});
	}
	for(int r = 1; r <= n; r++){
		update(a[r], r, 1, 0, N);
		for(auto [l, idx] : Right[r]){
			int j = find(l, 1, 0, N);
			if(j > (r-l+1)) assert(false);
			ans[idx] = j;
		}
	}
	for(int i = 0;i < q; i++) cout << ans[i] << '\n';
	return 0;
}

