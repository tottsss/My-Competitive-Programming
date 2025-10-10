#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
	tree_order_statistics_node_update> ordered_set;
 
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
const int N = 1e5 + 1;
int p[N]; int siz[N];
 
void make_set(int v){
	p[v] = v;
	siz[v] = 1;
}
 
int find_set(int v){
	if(v == p[v]) return v;
	return p[v] = find_set(p[v]);
}
 
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(siz[b] > siz[a]) swap(a, b);
	p[b] = a;
	siz[a]+= siz[b];
	siz[b] = a;
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<pair<int, pair<int, int> > > v;
	for(int i = 0;i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		v.push_back({w, {a, b}});
		// v.push_back({w, {a, b}});
	}
	for(int i = 1;i <= n; i++){
		make_set(i);
	}
	sort(v.begin(), v.end());
	int sum = 0LL;
	for(int i = 0;i < m; i++){
		int a = v[i].ss.ff, b = v[i].ss.ss, w = v[i].ff;
		if(find_set(a) == find_set(b)) continue;
		union_set(a, b);
		sum+= w;
	}
	
	
	
	 if(siz[find_set(1)] != n){
		 cout << "IMPOSSIBLE";
	 }else{
		cout << sum;
	 }
	return 0;
}