#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 5000;


int dp[N + 5][N + 5];


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n, q; n = s.size(); cin >> q;
	s = '#' + s;
	vector<int> even(n + 1), odd(n + 1);
	for(int i = 1;i <= n; i++){
		odd[i] = 1;
		dp[i][i] = 1;
		while(i-odd[i] >= 1 and i+odd[i] <= n){
			if(s[i-odd[i]] != s[i + odd[i]]){
				break;
			}
			dp[i-odd[i]][i+odd[i]]++;
			odd[i]++;
		}
		even[i] = 0;
		while(i-1-even[i] >= 1 and i + even[i] <= n){
			if(s[i-1-even[i]] != s[i + even[i]]) break;
			dp[i-1-even[i]][i + even[i]]++;
			even[i]++;
		}
	}

	for(int i = n;i >= 1; i--){
		for(int j = i+1;j <= n; j++){
			dp[i][j]+= dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
		}
	}
	while(q--){
		int l, r; cin >> l >> r;
		cout << dp[l][r] << '\n';
	}
	return 0;
}

