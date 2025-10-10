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
int cmp=0, mx_siz = 1;
void make_set(int v){
	p[v] = v;
	siz[v] = 1;
	cmp++;
}
 
int find_set(int v){
	if(v == p[v]) return v;
	return p[v] = find_set(p[v]);
}
 
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(siz[a] > siz[b]) swap(a, b);
	p[a] = b;
	siz[b]+= siz[a];
	siz[a] = b;
	cmp--;
	mx_siz = max(mx_siz, siz[find_set(b)]);
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int m; cin >> m;
	vector<int> g[n + 1];
	for(int i = 1;i <= n; i++){
		make_set(i);
	}
	set< pair<int, int> > st;
	
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		if(st.count({a, b})){
			cout << cmp << " " << mx_siz << "\n";
			continue;
		}
		union_set(a, b);
		cout << cmp << " " << mx_siz << "\n";
		st.insert({a, b});
	}
	return 0;
}