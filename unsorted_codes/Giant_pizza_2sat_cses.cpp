#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
 
const int N = 2e5;
 
 
int cinch(){
	char ch; cin >> ch;
	return (ch == '+' ? 1 : 0);
}
 
 
vector< pair<int, int> > g[N+5][2], G[N+5][2];
int used[N+5][2];
vector<pair<int, int> > ord;
 
void dfs(pair<int, int> A){
	auto [v, t] = A;
	used[v][t] = 1;
	for(auto [v1, t1] : g[v][t]){
		if(used[v1][t1]) continue;
		dfs({v1, t1});
	}
	ord.push_back({v, t});
}
int comp[N+5][2], timer = 1;
void scc(pair<int,int> A){
	auto [v, t] = A;
	used[v][t] = 1, comp[v][t] = timer;
	for(auto [v1, t1] : G[v][t]){
		if(used[v1][t1]) continue;
		scc(make_pair(v1, t1));
	}
}
 
 
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int q, n; cin >> q >> n;
	for(int i = 0;i < q; i++){
		int t = cinch(), x; cin >> x;
		int t1 = cinch(), x1; cin >> x1;
		g[x][t ^ 1].push_back({x1, t1});
		g[x1][t1^1].push_back({x, t});
		
		G[x1][t1].push_back({x, t^1});
		G[x][t].push_back({x1, t1^1});
		
	}
	
	for(int i = 0;i < 2; i++){
		for(int v = 1;v <= n; v++){
			if(!used[v][i]){
				dfs(make_pair(v, i));
			}
		}
	}
	for(int i = 0;i < 2; i++){
		for(int v = 1;v <= n; v++){
			used[v][i] = 0;
		}
	}
	reverse(all(ord));
	
	for(auto A : ord){
		if(used[A.ff][A.ss]) continue;
		scc(A);
		timer++;
	}
	
	for(int i = 1;i <= n; i++){
		if(comp[i][0] == comp[i][1]){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for(int i = 1;i <= n; i++){
		if(comp[i][0] > comp[i][1]) cout << '-';
		else cout << '+';
		cout << ' ';
	}
	cout << '\n';
	
	
	return 0;
}