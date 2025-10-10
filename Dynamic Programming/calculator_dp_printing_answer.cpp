#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> p(n+10, -1), dp(n+10, (int)1e9);
	dp[1] = 0;
	for(int i = 1;i <= n; i++){
		if(i*2 <= n and dp[i]+1 < dp[i*2]){
			dp[i*2] = dp[i]+1, p[i*2] = 2;
		}
		if(i*3 <= n and dp[i]+1 < dp[i*3]){
			dp[i*3] = dp[i]+1, p[i*3] = 3;
		}
		if(i+1 <= n and dp[i]+1 < dp[i+1]){
			dp[i+1] = dp[i]+1, p[i+1] = 1;
		}
	}
	string s;
    for(int par = n; par != 1; ){
    	s.push_back(p[par] + '0');
    	if(p[par] == 3) par/= 3;
    	else if(p[par] == 2) par/= 2;
    	else if(p[par] == 1) par--;
    	else{
    		assert(false);
		}
	}
	reverse(all(s));
	cout << s;
	return 0;
}

