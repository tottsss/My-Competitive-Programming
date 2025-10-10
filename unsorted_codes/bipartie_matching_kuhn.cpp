#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e5;
vector<int> g[N];
int used[N], par[N];
int timer = 1;
int B[N];
int compr[N];
int try_kuhn(int v){
	if(used[v] == timer){
		return 0;
	}
	used[v] = timer;
	for(int to : g[v]){
		if(par[to] == 0){
			par[to] = v;
			return 1;
		}
	}
	for(int to : g[v]){
		if(try_kuhn(par[to])){
			par[to] = v;
			return 1;
		}
	}
	return 0;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int nn = n;
	for(int j = 1;j <= m; j++){
		compr[j] = ++nn;
		B[nn] = j;
	}
	for(int a = 1;a <= n; a++){
		int b;
		while(cin >> b){
			if(b == 0) break;
			g[a].push_back(compr[b]);
		}
	}
	for(int i = 1;i <= n; i++){
		if(try_kuhn(i)){
			timer++;
		}
	}
	vector<pair<int, int> > ans;
	for(int i = 1;i <= n+m; i++){
		if(par[i] != 0){
			ans.push_back({i, par[i]});
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.ss << ' ' << B[x.ff] << '\n';
	return 0;
}

