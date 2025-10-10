#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int n, m;
vector<int> g[N+10];
int used[N+10];
set<pair<int, int> > ans;
void dfs(int v){
	used[v] = 1;
	for(int to : g[v]){
		if(!used[to])
		ans.insert({v, to});
	}
	for(int to : g[v]){
		if(!used[to]) dfs(to);
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<pair<int, int> > edge;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		edge.push_back({a, b});
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1;i <= n; i++){
		if(!used[i]) dfs(i);
	}
	for(auto x : edge){
		if(ans.count(x)) cout << x.ff << ' ' << x.ss;
		else if(ans.count(make_pair(x.ss, x.ff))) cout << x.ss << ' ' << x.ff;
		else{
			cout << "THIS ";
			cout << x.ff << ' ' << x.ss << '\n';
		}
		cout << '\n';
	}
	return 0;
}

