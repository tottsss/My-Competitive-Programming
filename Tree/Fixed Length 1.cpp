#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 2e5+1;
vector<int> g[N];
int   sub[N], mark[N];
int n, k,  len = 0;
int subtree(int v, int p){
	sub[v] = 1;
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		sub[v]+= subtree(to, v);
	}
	return sub[v];
}
 
int centroid(int v, int p, int sz){
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		if(sub[to] > sz/2){
			return centroid(to, v, sz);
		}
	}
	return v;
}
 
void calc_dist(int v, int p, int deep, vector<int> &dist){
	dist.push_back(deep);
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		calc_dist(to, v, deep+1, dist);
	}
}
 
void solve(int v){
	 subtree(v, -1);
	vector<int> cnt(sub[v], 0);
	cnt[0] = 1;
	mark[v] = 1;
	for(auto to : g[v]){
		if(mark[to]) continue;
		vector<int> dist;
		calc_dist(to, v, 1, dist);
		for(auto x : dist){
			if(k-x< sub[v] and k>= x){
				len+= cnt[k-x];
			}
		}
		for(auto x : dist){
			cnt[x]++;
		}
	}
	
	for(auto to : g[v]){
		if(mark[to]) continue;
		solve(centroid(to, v, sub[to]));
	}
}
 
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	subtree(1, -1);
	solve(centroid(1, -1, n));
	cout << len;
	return 0;
}