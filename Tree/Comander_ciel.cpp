#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
const int N = 2e5+1;
vector<int> g[N];
int sub[N], mark[N], chars[N];
int n;

int subtree(int v, int p){
	sub[v] = 1;
	for(auto to : g[v]){
		if(to == p or mark[to]) continue;
		sub[v]+= subtree(to, v);
	}
	return sub[v];
}
int centroid(int v, int p, int sz){
	for(auto to : g[v]){
		if(to == p or mark[to] == 1) continue;
		if(sub[to] > sz/2){
			return centroid(to, v, sz);
		}
	}
	return v;
}
void solve(int v, int A){
	sub[v] = subtree(v, -1);
	chars[v] = A;
	mark[v] = 1;
	for(auto to : g[v]){
		if(mark[to]) continue;
		solve(centroid(to, v, sub[to]), A+1);
	}
}
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	subtree(1, -1);
	int Cent = centroid(1, -1, n);
	solve(Cent, 0);
	for(int i = 1;i <= n; i++){
		cout << char(chars[i] + 'A') << " ";
	}
	return 0;
}