#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int n; cin >> n;
	vector< vector<pair<int, int>> > dp(n+5, vector<pair<int, int> >(n+5, {(int)1e9, 0}));
	vector<int> cost(n + 1);
	for(int i = 1;i <= n; i++){
		cin >> cost[i];
	}
//	dp[day][remCoupons] = {MinMoney, usedCoupons};
	dp[0][0]={0,0};
	for(int days = 1; days <= n; days++){
		for(int rem = 0; rem <= days; rem++){
			if(dp[days-1][rem + 1].ff < dp[days][rem].ff){
				dp[days][rem].ff = dp[days-1][rem+1].ff;
				dp[days][rem].ss = dp[days-1][rem+1].ss+1;
			}
			if(cost[days] > 100){
				if(rem > 0 and dp[days-1][rem-1].ff + cost[days] < dp[days][rem].ff){
					dp[days][rem] = {dp[days-1][rem-1].ff + cost[days], dp[days-1][rem-1].ss};
				}
			}else{
				if(dp[days-1][rem].ff + cost[days] < dp[days][rem].ff){
					dp[days][rem] = {cost[days] + dp[days-1][rem].ff, dp[days-1][rem].ss};
				}
			}
		}
	}
	int Mn = (int)1e9;
	pair<int, int> answer;
	for(int rem = 0; rem <= n; rem++){
		if(dp[n][rem].ff <= Mn){
			Mn = dp[n][rem].ff;
			answer = {rem, dp[n][rem].ss};
		}
	}
	cout << Mn << '\n';
	cout << answer.ff << ' ' << answer.ss;
	return 0;
}