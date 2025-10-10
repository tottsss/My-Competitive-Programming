#include "bits/stdc++.h" 
using namespace std;
const int N = 2e5+1;
#define int long long
vector<int> g[N];
int mark[N], sub[N];
int n, k, all;

int subtree(int v, int p){
	sub[v] = 1;
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		sub[v]+= subtree(to, v);
	}
	return sub[v];
}
int centroid(int v, int p, int sz){
	for(int to : g[v]){
		if(to == p or mark[to]) continue;
		if(sub[to] > sz>>1){
			return centroid(to, v, sz);
		}
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


void solve(int c){
	mark[c] = 1;
	subtree(c, -1);
	vector<int> cnt(sub[c], 0);
	cnt[0]=1;
	for(int to : g[c]){
		if(mark[to]) continue;
		vector<int> dist;
		calc_dist(to, c, 1, dist);
		for(auto x : dist){
			if(k-x>=0 and k-x<sub[c]){
				all+= cnt[k-x];
			}
		}
		for(int x : dist) cnt[x]++; 
	}
	for(int to : g[c]){
		if(mark[to]) continue;
		solve(centroid(to, c, sub[to]));
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
	cout << all;
	return 0;
}