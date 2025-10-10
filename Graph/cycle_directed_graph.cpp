#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int N = 1e5 + 10;
vector<int> g[N];
int par[N], used[N];
vector<int> ans;
void dfs(int v, int p){
	if(ans.empty() == false) return;
	used[v] = 1;
	par[v] = p;
	for(int to : g[v]){
		if(used[to] == 0){
			dfs(to, v);
		}else if(used[to] == 1){
			if(ans.empty() == false) return;
			for(int last = v; last != to and last != -1; last = par[last]){
				ans.push_back(last);
			} 
			ans.push_back(to);
			reverse(ans.begin(), ans.end());
			return;
		}
	}
	used[v] = 2;
}
 
main(){
	ifstream cin("cycle2.in");
	ofstream cout("cycle2.out");
	int n; cin >> n;
	int m; cin >> m;
	int petel = 0;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		if(a == b and petel == 0){
			cout << "YES" << '\n';
			cout << a << ' ' << b;
			petel = 1;
		}
		g[a].push_back(b);
	}
	if(petel) return 0;
	for(int i = 1;i <= n; i++){
		if(used[i] == 0) dfs(i, -1);
	}
	if(ans.empty()){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n'; 
		int v = ans.back();
		ans.pop_back();
		for(int x : ans) cout << x << ' ';
		cout << v;
	}
	return 0;
}