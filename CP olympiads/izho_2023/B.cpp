#include <bits/stdc++.h>
using namespace std;
#define ff  first
#define ss second
const int N = 5e5;
vector<int> g[N], g1[N];
int sub[N], n, sub1[N], depth[N], depth1[N];
int deg[N], deg1[N];
void dfs(int v, int p){
	if(v == p) depth[v] = 0;
	sub[v] = 1;
	for(auto to : g[v]){
		if(to == p) continue;
		depth[to] = depth[v]+1;
		dfs(to, v);
		sub[v]+= sub[to];
	}
}

void dfs1(int v, int p){
	if(v == p) depth1[v] = 0;
	sub1[v] = 1;
	for(auto to : g1[v]){
		if(to == p) continue;
		depth1[to] =depth1[v]+1;
		dfs1(to, v);
		sub1[v]+= sub1[to];
	}
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7
*/

/*
7
1 2
1 3
2 4
2 5
3 6
3 7

*/

main(){
	cin >> n;
	for(int i = 1;i < n; i++){
		int a,  b; cin >> a >> b;
		a--, b--;
		deg[a]++, deg[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		deg1[a]++, deg1[b]++;
		g1[a].push_back(b);
		g1[b].push_back(a);
	}
	if(n <= 2000){
		for(int i = 0;i < n; i++){
			dfs(i, i);
			dfs1(i, i);
			int cnt = 0;
//			cout << "the root is " << i+1 << '\n';
//			for(int j = 0;j < n; j++){
//				cout << sub[j] << ' ';
//			}
//			cout << '\n';
//			for(int j = 0;j < n; j++){
//				cout << sub1[j] << ' ';
//			}
//			cout << "the answer is ";
			for(int j = 0;j < n; j++){
				if(sub[j] > sub1[j]){
					cnt++;
				}
			}
			cout << cnt << ' ';
		}
//		cout << '\n';
		return 0;
	}
	int sz = 0;
	while((1<<sz) < n){
		sz++;
	}
	if(n != (1<<sz)-1) assert(false);
//	if(n == (1<<sz)-1) assert(false);
	int root = -1, root1 = -1;
	for(int i = 0;i < n; i++){
		if(deg[i] == 2){
			root = i;
		}
		if(deg1[i] == 2) root1 = i;
	}
	if(min(root, root1) == -1) assert(false);
	dfs(root, root);
	dfs1(root1, root1);
	set<int> vertex;
	for(int i = 0;i < n; i++){
		if(depth[i] < depth1[i]){
			vertex.insert(i);
//			cout<<i+1 << ' ';
		}
	}
//	cout << '\n';
	for(int i = 0;i < n; i++){
		if(vertex.count(i)){
			cout << vertex.size()-1;
		}else{
			cout << vertex.size();
		}
		cout << ' ';
	}
	return 0;
}