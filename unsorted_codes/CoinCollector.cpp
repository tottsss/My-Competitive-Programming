#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
vector<int> g[N+10], G[N+10];
int used[N+10], idx[N+10], c[N+10], coin[N+10], gr[N+10];
vector<int> order;
int n, m, s;
int num = 1;
void topsort(int v){
	used[v] = 1;
	for(int to : g[v]){
		if(used[to]==0){
			topsort(to);
		}
	}
	order.push_back(v);
}
void SCC(int v){
	used[v] = 1;
	idx[v] = num;
	for(int to : G[v]){
		if(used[to] == 0){
			SCC(to);
		}
	}
}
vector<int> cond[N+10];
int in_degree[N+10];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1;i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		G[b].push_back(a);
	}
	for(int v = 1; v <= n; v++){
		if(used[v] == 0){
			topsort(v);
		}
	}
	reverse(all(order));
	for(int i = 1;i <= n; i++) used[i] = 0;
	for(int v : order){
		if(used[v] == 0){
			SCC(v);
			num++;
		}
	}
	for(int i = 1;i <= n; i++){
		coin[idx[i]]+= c[i];
		gr[idx[i]]+= c[i];
	}
	for(int v = 1;v <= n; v++){
		for(int u : g[v]){
			if(idx[v] != idx[u]){
				cond[idx[v]].push_back(idx[u]);
				in_degree[idx[u]]++;
			}
		}
	}
	queue<int> q;
	for(int i = 1;i < num; i++){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}
//	cout << "Size " << num-1 << '\n';
	while(!q.empty()){
		int v = q.front(); q.pop();
//		cout << v << " ";
		for(int to : cond[v]){
			in_degree[to]--;
			coin[to] = max(gr[to] + coin[v], coin[to]);
			if(in_degree[to] == 0){
				q.push(to);
			}
		}
	}
//	cout << '\n';
	cout << *max_element(coin, coin + n + 1);
	return 0;
}

