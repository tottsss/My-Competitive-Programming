#include "bits/stdc++.h"

using namespace std;

#define int long long

int k;
vector <int> t, lazy;

void push(int v, int vl, int vr) {
	if(lazy[v] == (1LL << 32)) return;
	t[v]=lazy[v];
	if(vl!=vr){
		lazy[2*v+1]=lazy[v];
		lazy[2*v+2]=lazy[v];
	}
	lazy[v]=(1LL<<32);
}
void update(const int l, const int r, const int val, int vl = 0, int vr = k - 1, int v = 0) {
	push(v, vl, vr);
	if(vr < l || r < vl) return;
	if(l <= vl && vr <= r) {
		lazy[v] = val;
		push(v, vl, vr);
		return;
	}
	int vm = (vl + vr) / 2;
	update(l, r, val, vl, vm, 2*v+1);
	update(l, r, val, vm+1, vr, 2*v+2);
	t[v]=min(t[2*v+1], t[2*v+2]);
}
int get(const int l, const int r, int vl = 0, int vr = k - 1, int v = 0) {
	push(v, vl, vr);
	if(vr < l || r < vl) return (1LL<<32);
	if(l <= vl && vr <= r) return t[v];
	int vm = (vl + vr) / 2;
	auto L = get(l, r, vl, vm, 2*v+1);
	auto R = get(l, r, vm+1, vr, 2*v+2);
	return min(L, R);
}
int getVal(const int pos, int vl = 0, int vr = k - 1, int v  = 0) {
	push(v, vl, vr);
	if(vl == vr) return t[v];
	int vm = (vl + vr) / 2;
	if(pos <= vm) return getVal(pos, vl, vm, 2*v+1);
	else return getVal(pos, vm+1, vr, 2*v+2);
}
//https://codeforces.com/group/QmrArgR1Jp/contest/269449/problem/H
signed main (){
	 ifstream cin("rmq.in");
	 ofstream cout("rmq.out");
	int n, m;
	cin >> n >> m;
	k = 1; 
	while(k < n) k<<=1;
	t.resize(2*k-1,(1LL<<31)-1);
	lazy.resize(2*k-1, (1LL<<32));
	vector <pair <int,pair <int,int>>> query;
	for(int i = 0; i < m; i ++) {
		int l, r, ans;
		cin >> l >> r >> ans;
		l --, r --;
		query.push_back({ans, {l, r}});
	}
	sort(query.begin(), query.end());
	for(int i = 0; i < query.size(); i ++) {
		update(query[i].second.first, query[i].second.second, query[i].first);
	}
	for(int i = 0; i < query.size(); i ++) {
		int val = get(query[i].second.first, query[i].second.second);
		if(val == query[i].first) continue;
		cout << "inconsistent";
		return 0;
	}
	cout << "consistent\n";
	for(int i = 0; i < n; i ++) {
		cout <<  getVal(i) << " ";
	}
	return 0;
}