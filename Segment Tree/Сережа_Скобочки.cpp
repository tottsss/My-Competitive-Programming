#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
string s;
struct data{
	int Mx, open, close;
};
data tree[(1<<22)];

data combine(data a, data b){
	data res;
	res.Mx = a.Mx + b.Mx + min(a.open, b.close);
	res.open = a.open + b.open - min(a.open, b.close);
	res.close = a.close + b.close - min(a.open, b.close);
	return res;
}

void build(int v, int vl, int vr){
	if(vl == vr){
		if(s[vl] == ')'){
			tree[v] = {0, 0, 1};
		}else{
			tree[v] = {0, 1, 0};
		}
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1, vl, mid); build(v<<1|1, mid+1, vr);
	tree[v] = combine(tree[v<<1], tree[v<<1|1]);
}

data query(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return {0, 0, 0};
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	data L = query(l, r, v<<1, vl, mid);
	data R = query(l, r, v<<1|1, mid+1, vr);
	return combine(L, R);
}



main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	 cin >> s;
	s = "#" + s;
	int n= s.size(), q; cin >> q;
	build(1, 1, n);
	while(q--){
		int l, r; cin >> l >> r;
		cout << query(l, r, 1, 1, n).Mx * 2 << '\n';
	}
	
	return 0;
}