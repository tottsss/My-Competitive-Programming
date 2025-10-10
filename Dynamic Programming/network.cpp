#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int n; 
int a[19][19];
int dp[1<<19];
vector<int> g[19];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ifstream cin("network.in");
   ofstream cout("network.out");
	cin >> n;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			char ch; cin >> ch;
			if(ch == 'Y'){
				a[i][j] = 1;
				g[i].push_back(j);
			}
		}
	}
	dp[0] = 1;
	for(int i = 0;i < n; i++){
		for(auto to : g[i]){
			for(int mask = 0; mask < (1<<n); mask++){
				if(dp[mask] and !(mask & (1<<i))){
					if(!(mask & (1<<to))){
						int next = mask | (1<<i);
						next|= (1<<to);
						dp[next] = 1;
					}
				}
			}
		}
	}
	int answer = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		if(dp[mask]){
			answer = max(answer, __builtin_popcount(mask));
		}
	}
	cout << answer;
	return 0;
}

