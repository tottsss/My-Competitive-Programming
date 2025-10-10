#include "race.h"
#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second



int n, k, mn;
vector< pair<int, int> > g[200005];
void dfs(int v, int par, map<int, int> &mp, int depth, long long distance){
	mp[distance] = depth;
	for(auto [to, w] : g[v]){
		if(to == par) continue;
		map<int, int> sub;
		dfs(to, v, sub, depth + 1, distance + w);
		if(mp.size() < sub.size()) swap(mp, sub);
		for(auto &u : sub){
			int d = 2*distance - u.ff + k;
			if(mp.count(d)){
				mn = min(mn, mp[d] + u.ss - 2*depth);
			}
		}
		for(auto &u : sub){
			if(mp.count(u.ff)) mp[u.ff] = min(mp[u.ff], u.ss);
			else{
				mp[u.ff] = u.ss;
			}	
		}
	}
}


int best_path(int N, int K, int H[][2], int L[]){
	
	n = N, k = K, mn = N+1;
	for(int i = 0;i < n-1; i++){
		g[H[i][0]].push_back({H[i][1], L[i]});
		g[H[i][1]].push_back({H[i][0], L[i]});
	}
	map<int, int> mp;
	dfs(0, 0, mp, 0, 0);
	
	if(mn == n+1) mn = -1;
	return mn;
}

//main(){
//	int N, K; cin >> N >> K;
//	int H[N-1][2], L[N-1];
//	for(int i = 0; i < N-1; i++){
//		cin >> H[i][0] >> H[i][1];
//	}
//	for(int i = 0;i < N-1; i++) cin >> L[i];
//	cout << best_path(N, K, H, L);
//}
