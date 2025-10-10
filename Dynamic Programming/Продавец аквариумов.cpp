// author: i
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int a[15][15];

int n;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	vector< vector<int> > dp((1<<14), vector<int>(14, LLONG_MAX));
	vector< vector<int> > parent((1<<14), vector<int>(14, -1));
	cin >> n;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < n; i++){
		dp[(1<<i)][i] = 0;
	}
	for(int mask = 1; mask < (1<<n); mask++){
		int bits = __builtin_popcount(mask);
		int fr = __builtin_ctz(mask);
		if(bits < 2) continue;
		for(int last = 0; last < n; last++){
			// current masks last vertex	
			if(last == fr and !(mask & (1<<last))) continue;		
			int next = (mask ^ (1<<last));
			for(int pref = 0; pref < n; pref++){
				if(!(next & (1<<pref))) continue;
				if(dp[mask][last] > dp[next][pref] + a[last][pref]){
					parent[mask][last] = pref;
					dp[mask][last] = dp[next][pref] + a[last][pref];
				}
			}
		}
	}
	int answer = LLONG_MAX,  LAST;
	for(int i = 0;i < n; i++){
		if(answer > dp[(1<<n)-1][i]){
			LAST = i;
			answer = dp[(1<<n)-1][i];
		}
	}
	cout << answer << '\n';
	int cur = (1<<n)-1, pref;
	vector<int> path;
	for(int par = LAST; par != -1; par = parent[cur][par], cur = (cur ^ (1<<pref))){
		path.push_back(par+1);
		pref = par;
	}
	reverse(all(path));
	for(int i = 0;i < path.size(); i++){
		cout << path[i] << ' ';
	}
	return 0;
}

