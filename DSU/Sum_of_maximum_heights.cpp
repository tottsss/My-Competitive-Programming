#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
//abc214_d
vector< pair<int, pair<int, int> > > edge;
int n, sz[N], par[N];

int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	a = find_set(a), b = find_set(b);
	if(a==b)return;
	if(sz[b] > sz[a]) swap(a,b);
	sz[a]+= sz[b];
	par[b] = a;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		sz[i] = 1, par[i] = i;
		if(i == n-1) continue;
		int a, b; cin >> a >> b;
		a--, b--;
		int w; cin >> w;
		edge.push_back({w, {a, b}});
	}
	sort(all(edge));
	int answer  =0;
	for(auto x : edge){
		answer+= x.ff * sz[find_set(x.ss.ff)]*sz[find_set(x.ss.ss)];
		union_set(x.ss.ff, x.ss.ss);
	}
	cout << answer;
	return 0;
}

