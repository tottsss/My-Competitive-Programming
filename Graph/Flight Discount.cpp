#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e18 + 7;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector< pair<int, int> > g[n + 1];
	vector< pair<int, int> > G[n + 1];
	vector<int> dis_1(n + 1, INF);
	vector<int> dis_n(n + 1, INF);
	vector< pair<int, pair<int, int> > >edge; 
	int ans = INF;
	for(int i = 0;i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		edge.push_back({a, {b, c}});
		g[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	dis_1[1] = 0; dis_n[n] = 0;
	set< pair<int, int> > q;
	q.insert({dis_1[1], 1});
	while(!q.empty()){
		int v = q.begin()->second; q.erase(q.begin());
		for(auto u : g[v]){
			int to = u.ff;
			int len = u.ss;
			if(dis_1[to] > dis_1[v] + len){
				q.erase({dis_1[to], to});
				dis_1[to] = dis_1[v] + len;
				q.insert({dis_1[to], to});
			}
		}
	}
	q.insert({dis_n[n], n});
	while(!q.empty()){
		int v = q.begin()->second; q.erase(q.begin());
		for(auto u : G[v]){
			int to = u.ff; int len = u.ss;
			if(dis_n[to] > dis_n[v] + len){
				q.erase({dis_n[to], to});
				dis_n[to] = dis_n[v] + len;
				q.insert({dis_n[to], to});
			}
		}
	}
	for(int i = 0;i < m; i++){
		int a = edge[i].ff;
		int b = edge[i].ss.ff;
		int c = edge[i].ss.ss;
		ans = min(ans, dis_1[a] + dis_n[b] + (c/2LL));
		// ans = min(ans, dis_1[b] + dis_n[a] + (c / 2LL));
	}
	cout << ans;
	return 0;
}