#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1);
	int sum = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum+= a[i];
	}
	vector<int> dp(sum+5, 0);
	dp[0]=1;
	for(int i = 1;i <= n; i++){
		for(int j = sum;j-a[i] >=0; j--){
			dp[j] = max(dp[j], dp[j-a[i]]);
			
		}
	}
	int answer=0;
	for(int j = 0;j <= sum; j++){
		answer+= min(dp[j], 1);
	}
	// cout << endl;
	cout << answer;
	return 0;
}