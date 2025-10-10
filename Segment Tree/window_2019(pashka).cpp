#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 4e5 + 1, compress = 2e5;
pair<int, int> tree[4*N];
int lazy[4 * N];
struct Q{
	int l, r, x;
};

pair<int, int> combine(pair<int, int>a, pair<int, int> b){
	if(a.ff > b.ff) return a;
	return b;
}

void push(int v, int vl, int vr){
	if(lazy[v] == 0) return;
	tree[v].ff += lazy[v];
	if(vl != vr){
		lazy[v<<1|1] += lazy[v];
		lazy[v*2+2] += lazy[v];
	}
	lazy[v] = 0;
}
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = {0LL, vl};
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1|1, vl, mid);
	build(v*2+2, mid+1,vr);
	tree[v] = combine(tree[v<<1|1], tree[v*2+2]);
}

void add(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return;
	if(l <= vl and r >= vr){
		lazy[v]+= x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(l, r, x, v<<1|1, vl, mid);
	add(l, r, x, v*2+2, mid+1,vr);
	tree[v] = combine(tree[v<<1|1], tree[v*2+2]);
}
//
//pair<int, int> get_max(int l, int r, int v, int vl, int vr){
//	push(v, vl, vr);
//	if(vl > r or l > vr) return {INT_MIN, 0};
//	if(l <= vl and r >= vr){
//		return tree[v];
//	}
//	int mid = (vl + vr)>>1;
//	pair<int, int> L = get_max(l, r, v<<1|1, vl, mid);
//	pair<int, int> R = get_max(l, r, v*2+2, mid+1,vr);
//	tree[v] = combine(tree[v<<1|1], tree[v*2+2]);
//	return combine(L,R);
//}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, vector<Q> > query;
	int mx = INT_MIN;
	pair<int, int> answer = {-1, -1};
	for(int i = 0;i < n; i++){
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		query[y].push_back({x+compress, x1 + compress, 1});
		query[y1+1].push_back({x + compress, x1 + compress, -1});
	}
	build(0, 0, N);
	for(auto to : query){
		for(auto Q : query[to.ff]){
			add(Q.l, Q.r, Q.x, 0, 0, N);	
		}
		if(mx <= tree[0].ff){
			mx = tree[0].ff;
			answer ={tree[0].ss, to.ff};
		}
	}
	cout << mx << '\n' << answer.ff-compress << ' ' << answer.ss;
	return 0;
}

