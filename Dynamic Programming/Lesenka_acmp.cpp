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
	vector<int> dp(12345, 0);
	dp[0]=1;
	for(int i = 1;i <= n; i++){
		for(int j = (n * (n+1))/2; j >= i; j--){
			dp[j]+= (dp[j-i]);
		}
	}
	
	cout << dp[n];
	return 0;
}