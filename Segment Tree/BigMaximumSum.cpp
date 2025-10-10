#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = -1e16;
vector<int> a[51];
int n, m;

struct node{
	int sum, suf, pref, ans;
};
node tree[60][5123];


node New_node(int x){
	return {x, x, x, x};
}

node merge(node a, node b){
	node AB;
	AB.sum = a.sum + b.sum;
	AB.pref = max({0LL, AB.sum,  a.pref,  a.sum + b.pref});
	AB.suf = max({0LL, AB.sum,   b.suf, a.suf + b.sum});
	AB.ans = max({0LL, AB.pref, AB.sum, AB.suf, a.ans, b.ans, a.suf + b.pref});
	return AB;
}

void build(int v, int vl, int vr, int idx){
	if(vl == vr){
		if(vl >= a[idx].size()) tree[idx][v] = New_node(M);
		else
		tree[idx][v] = New_node(a[idx][vl]);
	}else{
		int mid = (vl + vr)>>1;
		build(v<<1|1, vl, mid, idx);
		build(v+v+2, mid+1, vr, idx);
		tree[idx][v] = merge(tree[idx][v<<1|1], tree[idx][v+v+2]);
	}
}
/*
4 3
6 6 8 -5 4 10 -2
1 -2
1 -10
5 -10 10 8 -7 -10

2 4 1
*/

main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<int> mx(n, M);
	int sz = 0, minus = M;
	for(int i = 0;i < n; i++){
		int l; cin >> l;
		sz+= l;
		for(int j = 0;j < l; j++){
			int x; cin >> x;
			mx[i] = max(mx[i], x);
			
			a[i].push_back(x);
		}
		build(0, 0, l-1, i);
	}
	int best = M;
	node res = {0,0,0,0};
	for(int i = 0;i < m; i++){
		int x; cin >> x; x--;
		minus = max(mx[x], minus);
		node to  = merge(res, tree[x][0]);
//		cout << tree[x][0].sum << ' ' << tree[x][0].pref << ' ' << tree[x][0].suf << ' ' << tree[x][0].ans << '\n';
		best = max(best, max({to.ans, to.pref, to.suf, to.sum}));
		best =max(best, max({tree[x][0].ans, tree[x][0].sum, tree[x][0].suf, tree[x][0].pref}));
		 res = to;
//		cout << res.sum << ' ' << res.pref << ' ' << res.suf << ' ' << res.ans << '\n';
	}
	if(minus < 0) cout << minus;
	else
	cout << best;
	return 0;
}