#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
const int M = 1e9+7;
const int P = 29;
const int N = 5e5;

int pw[N+10], A[N+10];

int get(int l, int r){
	return (((A[r]-A[l-1]*pw[r-l+1])%M)+M)%M;
}
vector< multiset<int> > g(N+1);
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	pw[0] = 1;
	for(int i = 1;i <=N; i++){
		pw[i] = (pw[i-1]*P)%M;
	}
	multiset<pair<int, int> > st;
	for(auto &s : a){
		cin >> s;
		for(int i = 1;i <= s.size(); i++){
			A[i] = A[i-1] + pw[i] * (s[i-1]-'a');
			A[i]%= M;
			g[i].insert(get(1, i));
		}
	}
	for(auto &s : a){
		int ok = 0;
		for(int i = 1;i <= s.size(); i++){
			A[i] = A[i-1] + pw[i] * (s[i-1]-'a');
			A[i]%= M;
			auto it = g[i].find(get(1, i));
			if(it != g[i].begin()){
				it--;
				if(*it == get(1, i)){
					ok = i;
				}
				it++;
			}
			it++;
			if(it != g[i].end()){
				if(*it == get(1, i)){
					ok = i;
				}
			}
			it--;
			if(ok == i-1) break;
		}
		cout << ok << '\n';
	}
	//https://atcoder.jp/contests/abc287/tasks/abc287_e
	return 0;
}

