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
	int a[n];
	vector<int> dp(n, 1), p(n, -1);
	for(int i = 0;i < n; i++) cin >> a[i];
	for(int i = 1;i < n; i++){
		int idx = -1;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				if(idx == -1 or dp[idx] < dp[j]){
					idx = j;
				}
			}
		}
		if(idx ==-1) continue;
		dp[i] = dp[idx]+1;
		p[i] = idx;
	}
	int idx = 0;
	for(int i = 1;i < n; i++){
		if(dp[idx] < dp[i]) idx = i;
	}
	cout << dp[idx] << '\n';
	vector<int> A;
	for(int par = idx; par != -1; par = p[par]){
		A.push_back(a[par]);
	}
	reverse(all(A));
	for(int x : A) cout << x << ' ';
	return 0;
}

