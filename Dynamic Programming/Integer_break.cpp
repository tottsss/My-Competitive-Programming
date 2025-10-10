#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n; cin >> n;
	vector<int> dp(n + 10, 0);
	dp[1] = 1;
    dp[2] = 1; dp[3] = 2;
    for(int i = 4;i <= n; i++){
    	for(int j = 1;j <= n; j++){
    		if(i - j >= 1){
    			dp[i] = max(dp[i], dp[i-j]*j);
    			dp[i] = max(dp[i], (i-j)*j);
			}
		}
	}
	cout << dp[n];
	return 0;
}

