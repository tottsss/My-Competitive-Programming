#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e18 + 7;
const int N = 1e5 + 1;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector< pair<int, int> > g[n + 1];
	vector< pair<int, pair<int, int> > > edge;
	for(int i = 0;i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		edge.push_back({w, {a, b}});
		// edge.push_back({w, {b, a}});
	}	
	vector<int> dis(n + 1, INF);
	vector<int> p(n + 1, -1);
	int found = -1;
	for(int i = 1;i <= n; i++){
		found = -1;
		for(auto to : edge){
			int a, b, w;
			w = to.ff; a = to.ss.ff; b = to.ss.ss;
			if(dis[b] > dis[a] + w){
				found = b;
				dis[b] = dis[a] + w;
				p[b] = a;
			}
		}
	}
	if(found == -1){
		cout << "NO";
	}else{
		cout << "YES" << "\n";
		// cout << found << " ->" << "\n";
		vector<int> parents;
		int y = found;
		for(int i = 0;i < n; i++){ 
			y = p[y];
			// cout << y <<" ";
		}
		// cout << y << "\n";
		for(int par = y; ; par = p[par]){
			if(par == y and parents.size() > 1) break;
			parents.push_back(par);
		}
		reverse(parents.begin(), parents.end());
		for(auto to : parents) cout << to << " ";
		cout << parents[0];
	}
	return 0;
}