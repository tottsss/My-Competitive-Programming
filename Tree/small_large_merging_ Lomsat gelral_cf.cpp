#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 1e5+1;
vector<int> g[N], c(N);
long long ans[N]; 
map<int, int> mp[N], cnt[N];
int n;

void merge(int a, int b){
	if(mp[a].size() < mp[b].size()){
		swap(mp[a], mp[b]);
		swap(cnt[a], cnt[b]);
	} 
	for(pair<int, int> x : mp[b]){
		int color = x.ff;
		int c = x.ss;
		mp[a][color]+= c;
		cnt[a][mp[a][color]]+= color;
	}
}
void dfs(int v, int par){
	mp[v][c[v]] = 1;
	cnt[v][1] =c[v];
	for(auto to : g[v]){
		if(to == par) continue;
		dfs(to, v);
		merge(v,to);
	}
	ans[v] = cnt[v].rbegin()->ss;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> c[i];
	}
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	for(int i = 1;i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}