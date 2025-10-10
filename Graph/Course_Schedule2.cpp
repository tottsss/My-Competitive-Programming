#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5;

int n, m;
vector<int> g[N + 10], topologic;
int used[N + 10], in_degree[N + 10];
priority_queue<int> q;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		g[b].push_back(a);
		in_degree[a]++;
	}
	
	for(int i = 1;i <= n; i++){
		if(in_degree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.top(); q.pop();
		topologic.push_back(v);
		for(auto to : g[v]){
			in_degree[to]--;
			if(!in_degree[to]){
				q.push(to);
			}
		}
	}
	reverse(all(topologic));
	for(auto x : topologic) cout << x << " ";
	return 0;
}

