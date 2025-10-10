#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int dp[51][51][51 * 55];
int n, A, x[51];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> A;
	int all = 0;
	for(int i = 1;i <= n; i++){
		cin >> x[i];
		all+= x[i];
	}
	dp[0][0][0] = 1;
	//https://atcoder.jp/contests/arc060/tasks/arc060_a
	for(int i = 1;i <= n; i++){
		for(int j = x[i]; j <= all; j++){
			for(int k = 0;k < i; k++){
				for(int elem = 0; elem <= k; elem++){
					dp[i][elem+1][j]+= dp[k][elem][j-x[i]];
				}
			}
		}
	}
	
	int sum = 0;
	for(int i = 1;i <= n; i++){
		for(int elem = 1; elem <= i; elem++){
			for(int j = 1; j <= all; j++){
				if(j%elem == 0 and j / elem == A){
					sum+= dp[i][elem][j];
				}
			}
		}
	}
	cout << sum;
	return 0;
}

