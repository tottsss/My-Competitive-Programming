#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;


int first_bit(int x){
	return __builtin_ctz(x);
}
int n, m;
int dp[1<<20][20];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	 cin >> n >> m;
	 vector<set<int> > g(n);
	for(int i = 0;i < m; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	for(int i = 0;i < n; i++){
		dp[(1<<i)][i] = 1;
	}
	for(int mask = 1; mask < (1<<n); mask++){
		int bits = __builtin_popcount(mask);
		if(bits < 2) continue;
		int First =__builtin_ctz(mask);
		for(int i = 0;i < n; i++){
			if(!(mask & (1<<i)) or i == First) continue;
			for(auto to : g[i]){
				if(!(mask & (1<<to))) continue;
				int next = mask ^(1<<i);
				dp[mask][i]+= dp[next][to];
			}
		}
	}
	int sum = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		if(__builtin_popcount(mask) >= 3){
			int First =__builtin_ctz(mask); 
			for(int i =0;i < n; i++){
				if((mask & (1<<i)) and g[i].count(First)){
					sum+= dp[mask][i];
				}
			}
		}
	}
	cout << sum/2;
	return 0;
}

