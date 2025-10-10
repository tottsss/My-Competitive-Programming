#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1000;

int Left[N], Right[N], used[N], timer = 1;
vector<int> g[N];
int n, m, k;

int try_kuhn(int v){
	if(used[v] == timer) return 0;
	used[v] = timer;
	for(int to : g[v]){
		if(Right[to] == 0){
			Right[to] = v;
			 Left[v] = to;
			return 1;
		}
	}
	for(int to : g[v]){
		if(try_kuhn(Right[to])){
			Right[to] = v, Left[v] = to;
			return 1;
		}
	}
	return 0;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0;i < k; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}
	for(int i = 1;i <= n; i++){
		if(try_kuhn(i)){
			timer++;
		}
	}
	vector<pair<int, int>> ans;
	for(int i = 1;i <= n; i++){
		if(Left[i] != 0){
			ans.push_back({i, Left[i]});
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x.ff << ' ' << x.ss << '\n';
	return 0;
}

