#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
vector<pair<int, int> > g[N+5];
int sub[N+5], p[N+5];
int n, edge[5+N];

void dfs(int v, int par){
	sub[v] = 1;
	for(pair<int, int> u : g[v]){
		if(u.ff != par){
			p[u.ff] = v;
			dfs(u.ff, v);
			edge[u.ss] = sub[u.ff]*(n-sub[u.ff]);
			sub[v]+= sub[u.ff];
		}
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	dfs(1, 1);
	int sum = 0;
	for(int i = 0;i < n-1; i++) sum+= edge[i];
	cout << sum;
	return 0;
}

