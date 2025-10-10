#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int N = 2e5+1;
vector<int> g[N];
int sub[N], mark[N], c[N];
int n;
long long len = 0;
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
		if(sub[to] > sz/2) return centroid(to, v, sz);
	}
	return v;
}
int calc_dist(int v, int p, int deep, vector<int>&dist){
	dist.push_back(deep);
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		calc_dist(to, v, (deep^c[to]), dist);
	}
}
void solve(int v){
	subtree(v, -1);
	vector< vector<int> > all(22, vector<int>(2, 0));
	len+= c[v];
	mark[v] = 1;
	for(auto to : g[v]){
		if( mark[to]) continue;
		vector<int> dist;
		calc_dist(to, v, c[to], dist);
		for(auto i : dist){
			for(int j = 0;j < 21; j++){
				if(i&(1<<j)){
					// one
					len+= (all[j][0] * (1LL<<j) * 1LL);
				}else{
					// zero
					len+= (all[j][1] * (1LL<<j) * 1LL);
				}
			}
			len+= (c[v]^i);
		}
		for(auto i : dist){
			for(int j = 0;j < 21; j++){
				int k = (i^c[v]);
				if(k&(1<<j)) all[j][1]++;
				else all[j][0]++;
			}
		}
	}
	for(auto to : g[v]){
		if(mark[to]) continue;
		solve(centroid(to, v, sub[to]));
	}
	
}
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> c[i];
	}
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