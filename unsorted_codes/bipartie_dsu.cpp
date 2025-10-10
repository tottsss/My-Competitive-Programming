#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e5;

int n, par[N], col[N];
vector<int> List[N];
string s;
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
	cin >> n >> s;
	for(int i = 0;i < n; i++){
		par[i] = i;
		List[i].push_back(i);
	}
	// https://codeforces.com/problemset/problem/1296/E1
	for(int i = 0;i < n; i++){
		for(int j = 0;j < i; j++){
			if(s[i] < s[j]){
				union_set(i, j);
			}
		}
	}
	cout << '\n';
	if(impossible) cout << "NO";
	else{
		cout << "YES" << '\n';
		for(int i = 0;i < n; i++){
			cout << col[i];
		}
	}
	return 0;
}

