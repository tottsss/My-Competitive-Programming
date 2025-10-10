#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> g[n+1];
	vector<int> answer(n+n,0); 
	int max_distance = 0;
	for(int i = 0;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<int> q;
	for(int i = 1;i <= n; i++){
		vector<int> dis(n+1,-1), cnt(n+1,0);
		dis[i] = 0; q.push(i); cnt[i] = 1;
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int to : g[v]){
				if(dis[to] == -1){
					dis[to] = dis[v]+1;
					cnt[to] = cnt[v]; 
					answer[dis[to]]+= cnt[v];
					q.push(to);
				}else if(dis[to] == dis[v]+1){
					cnt[to]+= cnt[v];
					answer[dis[to]]+= cnt[v];
				}
				max_distance = max(max_distance, dis[to]);
			}
		}
	}
//	cout << max_distance << '\n';
	cout << answer[max_distance]/2;
	return 0;
}

