#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1000;
const int LOG = 40;
int n, m, k;
int g[N+10][2], go[N+10];


pair<int, int> next(pair<int, int> s){
	pair<int, int> NEW = {g[s.ff][go[s.ss]], (s.ss+1) % m};
	return NEW;
}

main(){
	ifstream cin("cruise.in");
	ofstream cout("cruise.out");
	cin >> n >> m >> k;
	k*= m;
	for(int i = 1;i <= n; i++){
		cin >> g[i][0] >> g[i][1];
	}
	for(int i = 0;i < m; i++){
		char c; cin >> c;
		if(c == 'L') go[i] = 0;
		else go[i] = 1;
	}
	pair<int, int> s0 = {1, 0}, s1 = {1, 0};
	for(; k > 0; k--){
		s0 = next(s0);
		s1 = next(next(s1));
		if(s0.ff == s1.ff and s0.ss == s1.ss){
			k--;
			break;
		}
	}
	if(k){
		int cycle_siz = 1;
		for(s0 = next(s0); s0 != s1; cycle_siz++){
			s0 = next(s0);
		}

		k%= cycle_siz;
	}
	for(; k > 0; k--){
		s0 = next(s0);
	}
	
	cout << s0.ff;
	return 0;
}

