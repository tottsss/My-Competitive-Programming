#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 50000;
int n, m, q;
bitset<50000> reach[N];
vector<int> g[N], rev_g[N];
vector<int> new_g[N];
int used[N], scc, which[N]; 
vector<int> tp, comp[N];
void topsort(int v){
	used[v] = 1;
	for(int to : g[v]){
		if(used[to] == 0){
			topsort(to);
		}
	}
	tp.push_back(v);
} 
 
void condensation(int v){
	used[v] = 1;
	comp[scc].push_back(v);
	which[v] = scc;
	for(int to : rev_g[v]){
		if(used[to] == 0){
			condensation(to);
		}
	}
} 


void solve(int v){
	used[v] = 1;
	reach[v][v] = 1;
	for(int to : new_g[v]){
		if(used[to] == 0){
			solve(to);
		}
		reach[v]|= reach[to];
	}
}

 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b; 
		a--, b--;
		g[a].push_back(b);
		rev_g[b].push_back(a);
	}	
	for(int i = 0;i < n; i++){
		if(used[i] == 0){
			topsort(i);
		}
	}
	for(int i = 0;i < n; i++) used[i] = 0;
	reverse(all(tp));
	for(int i : tp){
		if(used[i] == 0){
			condensation(i);
			scc++;
		}
	}
	for(int i = 0;i < n; i++){
		for(int to : g[i]){
			if(which[to] != which[i])
			new_g[which[i]].push_back(which[to]);
		}
	}
	
	for(int i = 0;i < n; i++) used[i] = 0;
	for(int i = 0;i < scc; i++){
		if(used[i] == 0){
			solve(i);
		}
	}
	while(q--){
		int x, y; cin >> x >> y; x--, y--;
		 if(reach[which[x]][which[y]] == 1) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}