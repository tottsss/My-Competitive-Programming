#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int n, w; cin >> n >> w;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}	
	vector< pair<int, int> > dp(1<<19, {INT_MAX, INT_MAX});
	vector< vector<int> > path(1<<19);
	dp[0] = {1, 0};
	path[0] = {};
	for(int mask = 1; mask < (1<<n); mask++){
		pair<int, int> best = dp[mask];
		vector<int> best_path;
		for(int i = 0;i < n; i++){
			if(!(mask & (1<<i))) continue;
			int next = mask^(1<<i);
			pair<int, int> M = dp[next];
			vector<int> p = path[next];
			if(M.ss + a[i] > w){
				
				M.ff+= 1, M.ss = a[i];
			}else M.ss+= a[i];
			p.push_back(i);
			if(best.ss > M.ss and M.ff == best.ff){
				best = M;
				best_path = p;
			}else if(M.ff < best.ff){
				best = M;
				best_path = p;
			}
		}
		dp[mask] = best;
		path[mask] = best_path;
	}
	cout << dp[(1<<n)-1].first << '\n';
	vector<int> PA;
	int sum = 0;
	for(auto x : path[(1<<n) - 1]){
		PA.push_back(x);
		sum+= a[x];
		if(sum > w){
			PA.pop_back();
			cout <<PA.size() << " ";
			for(auto x : PA){
				cout << x + 1 << " ";
			}
			cout << endl;
			PA.clear();
			PA.push_back(x);
			sum = a[x];
		}
	}
	if(PA.empty() == false){
		cout << PA.size() << ' ';
		for(auto x : PA){
			cout << x + 1 << " ";
		}
	}
	return 0;
}