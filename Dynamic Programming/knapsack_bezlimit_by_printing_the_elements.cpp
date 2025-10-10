#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;
const int M = 1e9;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	int need; cin >> need;
	vector<int> dp(N+10, M);
	vector<int> p(N+10, -1);
	dp[0] = 0;
	for(int i = 1;i <= n; i++){
		for(int S = a[i]; S <= need; S++){
			if(dp[S] > dp[S-a[i]] + 1){
				dp[S] = dp[S-a[i]] + 1;
				p[S] = i;
			}
		}
	}
	vector<int> path;
	if(dp[need] >= M){
		cout << "No solution";
		return 0;
	}
	for(int par = p[need]; par != -1;need-= a[par],  par = p[need]){
		path.push_back(a[par]);
	}
	
	cout << path.size() << '\n';
	for(int x : path) cout << x << ' ';
	return 0;
}

