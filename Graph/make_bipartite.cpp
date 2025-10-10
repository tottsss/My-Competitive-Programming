#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
vector<int> g[N+1];
int colors[N+1][3];
int used[N+1], sz[N+1];
int all, cmp, one, two;

void dfs(int v, int col){
	used[v] = col;
	one+= (col==1);
	two+= (col==2);
	sz[cmp]++;
	for(auto to : g[v]){
		if(used[to] == 0){
			if(col == 1){
				dfs(to, 2);
			}else{
				dfs(to, 1);
			}
		}else{
			if(used[to] == used[v]){
				cout << 0;
				exit(0);
			}
		}
	}
}

/*
You are given a simple undirected graph G with N vertices and M edges
 (a simple graph does not contain self-loops or multi-edges). 
 For i=1,2,…,M, the i-th edge connects vertex ui​ and vertex

vi​.

Print the number of pairs of integers
(u,v) that satisfy

1≤u<v≤N and both of the following conditions.

    The graph 

G does not have an edge connecting vertex u and vertex
v.
Adding an edge connecting vertex
u and vertex v in the graph G results in a bipartite graph.
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   	int n, m; cin >> n >> m;
   	for(int i = 0;i < m; i++){
   		int a, b; cin >> a >> b;
   		g[a].push_back(b);
   		g[b].push_back(a);
	}
	cmp = 1;
	int pref = 0;
	for(int i = 1;i <= n; i++){
		if(used[i] ==0){
			one =0, two = 0;
			dfs(i, 1);
			all+= (one*two);
			all+= (sz[cmp]*pref);
			pref+= sz[cmp];
			cmp++;
		}
	}
	
	int cnt = 0;
	for(int i = 1;i <= n; i++){
		for(auto to : g[i]){
			if(used[to] != used[i]){
				cnt++;
			}
		}
	}
	cout << all - (cnt / 2);
	return 0;
}

