#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 100;
#define ff first
#define ss second
const int N = 2 * 1e5 + 5;
vector<int> a(2 * N);
vector< pair<int, int> > tree(4 * N);
int siz = 1;
pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	if(a.ff > b.ff) return a;
	else if(b.ff > a.ff) return b;
	else if(a.ss > b.ss) return b;
	else return a;
}
 
 
void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = make_pair(a[vl], vl);
		
	}else{
	int m = (vl + vr) / 2;
	build(v *2 + 1, vl, m); 
	build(v * 2 + 2, m + 1, vr);
	tree[v] = combine(tree[v * 2 + 1], tree[v * 2+2]);
	}
}
void get(int x, int v, int vl, int vr){
	
	if(vl ==vr){
		cout <<tree[v].ss+1;
		tree[v].ff -= x;
		
	}else{
		int m = (vl + vr) / 2;
		if(tree[v * 2 + 1].ff >= x)
		get(x, v * 2 + 1, vl, m);
		else
		get(x, v * 2 + 2, m + 1, vr);
		tree[v] = combine(tree[v * 2 + 1], tree[v * 2+2]);
	}
}
 
main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	while(n > siz) siz*= 2;
	tree.assign(2 * siz + 100, {-INF, 0});
	build(0, 0, siz);
	for(int i = 0;i < m; i++){
		int x;
		cin >> x;
		if(tree[0].ff < x) cout << 0;
		else get(x, 0, 0, siz);
		cout << ' ';
	}
	return 0;
}