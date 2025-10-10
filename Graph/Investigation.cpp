#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e18 + 7;
const int MOD = 1e9 + 7;
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector< pair<int, int> > g[n + 1];
	for(int i = 0;i < m; i++){
		int a, b, w; cin >> a >>b >> w;
		g[a].push_back({b, w});
		// g[b].push_back({a, w});
	}
	vector<int> dis(n + 1, INF);
	set< pair<int, int> > q;
	vector<int> counter(n + 1, 0);
	vector<int> Maxsiz(n + 1, -1);
	vector<int> Minsiz(n + 1, m+1);
	dis[1] = 0; counter[1] = 1;
	Minsiz[1] = 0;
	Maxsiz[1] = 0;
	q.insert({dis[1], 1});
	int edges = 0;
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for(auto u : g[v]){
			int to = u.ff;
			int len = u.ss;
			if(dis[to] == dis[v] + len){
				counter[to]+= (counter[v] % MOD); 
				counter[to]%= MOD;
				Minsiz[to] = min(Minsiz[to], Minsiz[v]+1);
				Maxsiz[to] = max(Maxsiz[to], Maxsiz[v]+1);
			}else if(dis[to] > dis[v] + len){
				q.erase({dis[to], to});
				dis[to] = dis[v] + len;
				counter[to] = counter[v]%MOD;
				Minsiz[to] = Minsiz[v]+1;
				Maxsiz[to] = Maxsiz[v]+1;
				q.insert({dis[to], to});
			}
			
		}
	}
	cout << dis[n] << " " << counter[n]%MOD << " " << Minsiz[n] << " ";
	cout << Maxsiz[n];
	return 0;
}