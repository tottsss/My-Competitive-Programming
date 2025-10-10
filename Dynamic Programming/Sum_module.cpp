#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e3;


int dp[N+10][N+10];

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	map<int, int> sum;
	sum[0] = 1;
	int cursum = 0;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		a[i]%= k;
	}
	sort(a, a + n);
	for(int i = 0;i < n; i++){
		cursum+= a[i];
		if(sum.count(cursum%k)){
			cout << "YES";
			return 0;
		}
		sum[cursum%k]=1;
	}
	// ????? ?? ?????? 577B
	for(int i = 0;i < n; i++){
		dp[i][a[i]%k]=1;
	}
	for(int i = 1;i < n; i++){
		for(int j = 0;j < k; j++){
			if(dp[i-1][j] == 1){
				dp[i][j] = 1;
				dp[i][(j + a[i])%k]=1;
			}
		}
	}
	cout << (dp[n-1][0]==1 ? "YES" : "NO");
	return 0;
}