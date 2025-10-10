#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e4;
int par[501], sz[501];
int comp;
int n, m, q;


int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}

int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return 0;
	if(sz[a] < sz[b]) swap(a, b);
	comp--;
	sz[a] += sz[b];
	par[b] = a; 
	return 1;
}

struct E{
	int t, a, b;
};


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<E> left, right;
	vector< pair<int, int> > v(m);
	for(int i = 1;i <= n; i++){
		sz[i] = 1, par[i] = i;
	}
	for(int i = 0;i < m; i++){
		cin >> v[i].ff >> v[i].ss;
	}
	for(int i = 0;i < m; i++){
		if(union_set(v[i].ff, v[i].ss)){
			left.push_back({i+1, v[i].ff, v[i].ss});
		}
	}
	for(int i = 1;i <= n; i++){
		sz[i] = 1, par[i] = i;
	}
	for(int i = m-1;i >= 0; i--){
		if(union_set(v[i].ff, v[i].ss)){
			right.push_back({i+1, v[i].ff, v[i].ss});
		}
	}
//	https://codeforces.com/contest/292/problem/D
	cin >> q;
	while(q--){
		int L,R; cin >> L>>R;
		for(int i = 1;i <= n; i++){
			sz[i] = 1, par[i] = i;
		}
		comp = n;
		
		for(E x : left){
			if(x.t >= L) break;
			union_set(x.a, x.b);
		}
		for(E x : right){
			if(R >= x.t) break;
			union_set(x.a, x.b);
		}
		cout << comp << "\n";
	}
	return 0;
}

