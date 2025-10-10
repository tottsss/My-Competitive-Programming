#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
int LIS(vector<int> q, int can, int n){
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
	int mx = 0;
	for(int i = 1;i <= n; i++){
		if(dp[i] < INT_MAX){
			mx = max(mx, i);
		}
	}
	return mx;
}


/*
5
5 4 1 2 3

*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int mx = 0, cnt = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		if(mask & 1) continue; 
		vector<int> q;
		for(int i = n-1; i >= 0; i--){
			if(mask & (1<<i)) q.push_back(a[i]);
		}
		for(int i = 0;i < n; i++){
			if(!(mask & (1<<i))) q.push_back(a[i]);
		}
		int len = LIS(q, -1, n);
		if (mx < len) {
			mx = len, cnt = 1;
		} else {
			cnt+= (mx == len);
		}
	}
		cout << mx << " 0";
	

	return 0;
}