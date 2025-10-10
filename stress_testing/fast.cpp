#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
vector<int> lis;
int n;
int LIS(vector<int> q, int can){
	vector<int> dp(n + 1, INT_MAX);
	if(can != -1){
		dp[0] = can-1;
	}else{
		dp[0] = INT_MIN;
	}
	for(int i = 0;i < n; i++){
		int j = upper_bound(all(dp), q[i]) - dp.begin();
		if(j > 0 &&  dp[j-1] < q[i] && q[i] < dp[j]){
			dp[j] = q[i];
		}
	}
	for(int i = 1;i <= n; i++){
		if(dp[i] < INT_MAX){
			lis.push_back(dp[i]);
		}else break;
	}
	return (int)lis.size();
}


/*
10
4 2 7 5 7 1 5 3 6 6

*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}	
	int mx = 0;
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = INT_MIN;
	reverse(all(a));
	for(int i = 0;i < n; i++){
		int j = upper_bound(all(dp), a[i]) - dp.begin();
		if(j > 0 &&  dp[j-1] < a[i] && a[i] < dp[j]){
			dp[j] = a[i];
		}
	}
	reverse(all(a));
	for(int i = 1;i <= n; i++){
		if(dp[i] < INT_MAX){
			mx = max(mx, i);
		}
	}
	LIS(a, -1);
	mx = max(mx, (int)lis.size());
	for(int x : lis) cout << x << ' ';
	cout << '\n';
	cout << mx << '\n';

	for(int i = 0;i <= n; i++){
		if(dp[i] == INT_MAX) break;
		int up = upper_bound(all(lis), dp[i]) - lis.begin();
		mx = max(mx, i + (int)lis.size() - up);
	}
	cout << mx << " 0";
	
	
	return 0;
}