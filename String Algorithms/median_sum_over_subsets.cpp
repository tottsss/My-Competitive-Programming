#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



bitset<2000*2010> dp;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	int sum = 0; dp[0] = 1;
	for(int i =0;i < n; i++){
		cin >> a[i];
		sum+= a[i];	
		dp|= (dp<<a[i]);
	}
	for(int i = (sum + 1) / 2; i <= sum; i++){
		if(dp[i] == 1){
			cout << i;
			return 0;
		}
	}
	return 0;
}

