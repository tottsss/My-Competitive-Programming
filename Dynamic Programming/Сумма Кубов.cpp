#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int sqrt_3(int n){
	int sq = 1;
	while(sq *sq * sq <= n){
		sq++;
	}
	if(sq * sq * sq > n) sq--;
	return sq;
}


void rec(int cur, vector<int> answer){
	if(answer.size() > 8) return;
	if(cur < 0) return;
	if(cur == 0){
		for(auto x : answer){
			cout << x << " ";
		}
		exit(0);
	}
	if(answer.size() == 8) return;
	int SQ = sqrt_3(cur);
	for(int i = SQ; i > 0 and i >= SQ-5; i--){
		if(i * i *i > cur) continue;
		answer.push_back(i);
		rec(cur - (i * i *i) , answer);
		answer.pop_back();
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> C;
	rec(n, C);
	cout << "IMPOSSIBLE";
	return 0;
}

