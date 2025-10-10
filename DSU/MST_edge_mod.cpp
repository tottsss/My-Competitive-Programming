#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
const int NUMS = 1e7;
int par[NUMS+1], sz[NUMS+1], cnt[NUMS+1], up[NUMS+1], Divs[NUMS+1];
int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}
long long ans;			
void union_set(int a, int b, int c){
//	cout << a << ' ' << b << ' '  << c << '\n';
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	
	ans+= c;
	sz[a]+= sz[b];
	par[b] = a;
}
int a[N+1], n;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n;
   vector<int> v;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);	
	}
	for(int i = 1;i <= NUMS; i++){
		par[i] = i, sz[i] = 1;
	}		
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for(auto x : v) cnt[x] = 1;
	for(int i = 1;i < v[0]; i++) up[i] = v[0];
	for(int i = 1; i < v.size(); i++){
		for(int k = v[i-1]; k < v[i]; k++) up[k] = v[i];
	}
	if(cnt[1]){
		cout << 0;
		return 0;
	}
	vector< pair<int, pair<int,int>>> edge;
	for(int i = 1;i <= NUMS; i++){
		if(!cnt[i]) continue;
		if(Divs[i]) continue;
		for(int j = i; j <= NUMS; j+= i){
			if(cnt[j]) union_set(i, j, 0);
			if(up[j] != 0 and up[j] < (j+i)){
				if(cnt[up[j]])
				edge.push_back({up[j]%i, {i, up[j]}});
			}
			Divs[j] = i;
		}
		
	}
	sort(all(edge));
	for(auto [x, u] : edge){
		union_set(u.ff, u.ss, x);
	}
	cout << ans;
	
	return 0;
}