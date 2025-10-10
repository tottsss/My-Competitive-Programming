#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e10;
int a[16][16], n;
vector<int> dp, calc;

void rec(int i, vector<int> &not_taken, int score, int mask, int group){
	if(i == not_taken.size()){
		dp[mask] = max(dp[mask], score + calc[group]);
		return;
	}
	rec(i+1, not_taken, score, mask, group);
	rec(i+1, not_taken, score, mask^(1<<not_taken[i]), 
		group^(1<<not_taken[i]));
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
		}
	}
	dp.resize((1<<n), -mod);
	calc.resize((1<<n), 0);
	for(int mask = 0; mask < (1<<n); mask++){
		for(int i = 0;i < n; i++){
			if(!(mask & (1<<i))) continue;
			for(int j = i+1;j < n; j++){
				if(!(mask & (1<<j))) continue;
				calc[mask]+= a[i][j];
			}
		}
	}
	dp[0] = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		vector<int> not_taken;
		for(int i = 0;i < n; i++){
			if(mask & (1<<i)) continue;
			not_taken.push_back(i);
		}
		rec(0, not_taken, dp[mask], mask, 0);
	}
	cout << dp[(1<<n)-1];
	return 0;
}

