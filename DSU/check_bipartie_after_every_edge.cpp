#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 2e6;

int n, par[N+10], col[N+10];
vector<int> List[N+10];
int m, A[N+1], B[N+1];
bool impossible = false;
int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	int f = (col[a] == col[b]);
	a = find_set(a);
	b = find_set(b);
	if(a == b){
		if(f) impossible = true;
		return;
	}
	if(List[a].size() < List[b].size()) swap(a, b);
	par[b] = a;
	while(List[b].empty() == false){
		List[a].push_back(List[b].back());
		col[List[b].back()]^= f; 
		List[b].pop_back();
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		par[i] = i;
		List[i].push_back(i);
	}
	for(int i = 0;i < m; i++){
		cin >> A[i];
	}
	for(int i = 0;i < m; i++){
		int b; cin >> b;
		union_set(A[i], b);
		if(impossible){
			cout << "-1" << '\n';
			cout << i+1;
			return 0;
		}
	}
	vector<int> v;
	for(int i = 1;i <=n; i++){
		if(col[i]==1) v.push_back(i);
	}
	cout << v.size() << '\n';
	for(int x : v) cout << x << ' ';
	return 0;
}

