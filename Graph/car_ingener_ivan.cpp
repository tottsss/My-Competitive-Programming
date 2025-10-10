#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int INF = 1e9 + 7;
const int N = 1e5;

//struct edge{
//	int to, x, y;
//};
//vector<edge> g[N];
vector<int> g[N][2];
int n, m, s, f, p[N], dis[N][2];
set<pair<int, pair<int, int> > > st;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		g[a][0].push_back(b);
		g[b][1].push_back(a);
	}
	cin >> s >> f;
	
	// acm timus 1930
	for(int i = 1;i <= n; i++) dis[i][0] = INF, dis[i][1] = INF;
	dis[s][0] = 0, dis[s][1] = 0;
	st.insert({dis[s][0], {s, 0}});
	st.insert({dis[s][1], {s, 1}});
	while(!st.empty()){
		int v = st.begin()->ss.ff;
		int v1 = st.begin()->ss.ss;
		st.erase(st.begin());
		for(auto to : g[v][v1]){
			if(dis[to][v1] > dis[v][v1]){
				st.erase({dis[to][v1], {to, v1}});
				dis[to][v1] = dis[v][v1];
				st.insert({dis[to][v1], {to, v1}});
			}
		}
		for(auto to : g[v][v1^1]){
			if(dis[to][v1^1] > dis[v][v1] + 1){
				st.erase({dis[to][v1^1], {to, v1^1}});
				dis[to][v1^1] = dis[v][v1] + 1;
				st.insert({dis[to][v1^1], {to, v1^1}});
			}
		}
	}
	
	cout << min(dis[f][0], dis[f][1]);
	return 0;
}

