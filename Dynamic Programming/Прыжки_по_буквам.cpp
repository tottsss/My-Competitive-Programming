#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> dp(n + 10, INT_MAX);
	dp[0] = 0;
	multiset<pair<int, char> > st;
	st.insert({0, s[0]});
	for(int i = 1;i < k; i++){
		int beg = st.begin()->first;
		if(st.count({beg, s[i]})){
			dp[i] = min(dp[i], beg);
		}else{
			dp[i] = min(dp[i], beg+1);
		}
		st.insert({dp[i], s[i]});
	}
	for(int i = k;i < n; i++){
		
		int beg = st.begin()->first;
		if(st.count({beg, s[i]})){
			dp[i] = min(dp[i], beg);
		}else{
			dp[i] = min(dp[i], beg+1);
		}
		
		st.insert({dp[i], s[i]});
		st.erase(st.find({dp[i-k], s[i-k]}));
	}
	cout << dp[n-1];
	return 0;
}