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
	
	int need; cin >> need;
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1;i <= n; i++) cin >> a[i];
	int m; cin >> m;
	vector<int> b(m+1);
	for(int i = 1;i <= m; i++){
		cin >> b[i];
	}
	vector<int> dp(N+10, M), dp1(N+1, M), p(N+10, -1), p1(N+10, -1);
	dp[0] = 0, dp1[0] = 0;
	for(int i = 1;i <= n; i++){
		for(int S = N; S >= a[i]; S--){
			if(dp[S] > dp[S-a[i]] + 1 and p[S] == -1){
				dp[S] = dp[S-a[i]] + 1;
				p[S] = i;
			}
		}
	}
	for(int i = 1;i <= m; i++){
		for(int S = N; S >= b[i]; S--){
			if(dp1[S] > dp1[S-b[i]] + 1 and p1[S] == -1){
				dp1[S] = dp1[S-b[i]] + 1;
				p1[S] = i;
			}
		}
	}
	vector<pair<char, int> > answer;
	for(int i = need; i <= N; i++){
		if(dp[i] < M and dp1[i-need] < M){
			int s = i;
			int sum = 0;
			for(int par = p[s]; par != -1; s-= a[par], par = p[s]){
				answer.push_back({'+', a[par]});
				sum+= a[par];
			}
			s = i-need;
			for(int par = p1[s]; par != -1; s-= b[par], par = p1[s]){
				answer.push_back({'-', b[par]});
				sum-= b[par];
			}
			if(sum != need){
				answer.clear();
				continue;
			}
			break;
		}
	}
	
	if(answer.empty()){
		cout << "Impossible";
	}else{
		for(auto x : answer) cout << x.ff << x.ss << ' ';
	}
	return 0;
}