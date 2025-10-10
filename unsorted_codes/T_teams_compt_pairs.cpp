#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int n, t, m; 
int cant[20][20];
vector< vector<int> > teams;
int ans;


int can(vector<int> &a, int u){
	for(int v : a){
		if(cant[u][v]) return 0;
	}
	return 1;
}

void dfs(int i){
	if(i == n){
		ans+= (teams.size() == t);
		return;
	}
	if(teams.size() < t){
		teams.push_back({i});
		dfs(i+1);
		teams.pop_back();
		
	}
	for(int j = 0;j < teams.size(); j++){
		if(can(teams[j], i)){
			teams[j].push_back(i);
			dfs(i+1);
			teams[j].pop_back();
		}	
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> t >> m;
	for(int i = 0;i < m; i++){
		int u, v; cin >> u >> v;
		u--, v--;
		cant[u][v] = cant[v][u] = 1;
	}
	dfs(0);
	cout << ans;
	return 0;
}

