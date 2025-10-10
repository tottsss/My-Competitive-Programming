#include "bits/stdc++.h"
 
using namespace std;
const int N = 2e5+1;
int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
vector<int> g[N];
vector<int> tree(4*N);
int sub[N], mark[N];
int n, l, r, k;
long long len; 
 
int subtree(int v, int p){
	sub[v] = 1;
	for(int to : g[v]){
		if(to == p or mark[to]) continue;
		sub[v]+= subtree(to, v);
	}
	return sub[v];
}
 
int centroid(int v, int p, int sz){
	for(int to : g[v]){
		if(to == p or mark[to]) continue;
		if(sub[to] > sz>>1) return centroid(to,v,sz);
	}
	return v;
}
 
void calc_dist(int v, int p, int deep, vector<int>&dist){
	dist.push_back(deep);
	for(int to : g[v]){
		if(to == p or mark[to]) continue;
		calc_dist(to, v, deep+1, dist);
	}
}
 
void solve(int v){
	subtree(v, -1);
	int siz = sub[v];
	mark[v] = 1;
	vector<int> cnt(sub[v]+1, 0);
	cnt[0] =1;
	tree.assign(4*siz, 0);
	function<void(int, int, int, int, int)> update=[&](int pos, int x, int v, int vl, int vr){
		if(vl == vr){
			tree[v] = x;
			return;
		}
		int mid = (vl + vr)>>1;
		if(mid>= pos) update(pos, x, v<<1|1, vl, mid);
		else update(pos, x, (v<<1)+2, mid+1, vr);
		tree[v] = tree[v<<1|1] +tree[(v<<1)+2];
	};
	function<void(int, int, int)> build=[&](int v, int vl, int vr){
		if(vl == vr){
			tree[v] = cnt[vl];
			return;
		}	
		int mid = (vl + vr)>>1;
		build(v<<1|1, vl, mid);
		build((v<<1)+2, mid+1, vr);
		tree[v] = tree[v<<1|1] + tree[(v<<1)+2];
 	};
	update(0, 1, 0, 0, siz);
//build(0, 0, siz);
	function<int(int, int, int, int, int)> query=[&](int l, int r, int v, int vl, int vr){
		if(l>vr or vl > r) return 0;
		if(l<= vl and r >= vr) return tree[v];
		int mid = (vl + vr) >>1;
		int A = query(l, r, v<<1|1, vl, mid);
		int B = query(l, r, (v<<1)+2, mid+1, vr);
		return (A+B);	
	};
	for(int to : g[v]){
		if(mark[to]) continue;
		vector<int> dist;
		calc_dist(to, v, 1, dist);
		for(int x : dist){
			int L = max(0, l-x), R = min(sub[v], r-x);
			len+= query(L, R, 0, 0, siz);
//			if(k>= x and k-x<sub[v]){
//				len+= cnt[k-x];
//			}
		}
		for(int x : dist){
			cnt[x]++;
			update(x, cnt[x], 0, 0, siz);	
		}
//		build(0, 0, siz);
	}
	for(auto to : g[v]){
		if(mark[to]) continue;
		solve(centroid(to, v, sub[to]));
	}
}
 
 
main(){
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	n = read_int();
	l = read_int();
	r = read_int();
	for(int i = 0;i < n-1; i++){
		int a = read_int();
		int b = read_int();
		g[a].push_back(b);
		g[b].push_back(a);
	}
	subtree(1, -1);
	solve(centroid(1, -1, n));
	cout << len;
	return 0;
}