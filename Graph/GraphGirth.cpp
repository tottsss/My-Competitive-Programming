#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> g[n];
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int answer = INT_MAX;
	for(int i = 0;i < n; i++){
		vector<int> dis(n, -1); dis[i] = 0;
		queue<int> q; q.push(i);
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(auto to : g[v]){
				if(dis[to] == -1){
					dis[to] = dis[v]+1;
					q.push(to); 
				}else if(dis[to] >= dis[v]){
					answer = min(answer, dis[v] + dis[to] + 1);
				}
			}
		}
	}
	if(answer == INT_MAX) answer = -1;
	cout << answer;
	return 0;
}

