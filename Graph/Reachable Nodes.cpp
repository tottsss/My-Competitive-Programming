#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5e4 + 100;
int n, m, q;
vector< bitset<N> > A(N);
vector<int> g[N], done(N);
 
void solve(int v){
	if(done[v] == 1) return;
	A[v][v] = 1;
	for(auto to : g[v]){
		solve(to);
		A[v]|= A[to];
	}
	done[v] = 1;
}
 
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
	}	
	for(int i = 0;i < n; i++){
		solve(i);
	}
	for(int i = 0;i < n; i++){
		cout << A[i].count() << ' ';
	}
	return 0;
}