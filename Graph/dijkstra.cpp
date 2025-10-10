#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int INF = 1e9 + 7;
const int N = 1e5;
vector<pair<int, int> > g[N];
int n, m, s, f, p[N];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> f;
    s--, f--;
    for(int i = 0;i < m; i++){
    	int a, b, c; cin >> a >> b >> c;
    	a--, b--;
    	g[a].push_back({b, c});
    	g[b].push_back({a, c});
	}
    vector<int> d(n + 1, INF);
    d[s] = 0, p[s] = -1;
    priority_queue< pair<int, int> > q;
    q.push(make_pair(d[s], s));
    while(!q.empty()){
        int v = q.top().second;
        int curlen = q.top().first;
        curlen = -curlen;
        q.pop();
        if(curlen > d[v]) continue;
        for(int i = 0;i < g[v].size(); i++){
            int to = g[v][i].first;
            int len = g[v][i].second;
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair(-d[to], to));
            }
        }
    }
     
    if(d[f] >= INF) cout << "-1";
    else{
    	cout << d[f] << '\n';
    	vector<int> path;
    	for(int par = f; par != -1; par = p[par]){
    		path.push_back(par+1);
		}
		reverse(all(path));
		for(int x : path) cout << x << ' ';
	}

	return 0;
}

