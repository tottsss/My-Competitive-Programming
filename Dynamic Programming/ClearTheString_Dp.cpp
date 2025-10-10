#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
vector< vector<int> > dp(512, vector<int>(512, -1));
int n; string s;


void update(int l, int r, int x){
	if(l < 0 or r < 0) return;
	if(dp[l][r] == -1) dp[l][r] = x;
	else dp[l][r] = min(dp[l][r], x);
}


int calc(int l, int r){
	if(l > r) return 0;
	int res = dp[l][r];
	if(res != -1) return res;
	if(l == r){
		dp[l][r] = 1;
		return 1;
	}
	res = 1 + calc(l+1, r);
	for(int i = l+1; i <= r; i++){
		if(s[i] == s[l]){
			int s = calc(i, r);
			int s1 =  calc(l+1, i-1);
			res = min(res, s + s1);
			update(i, r, s);
			update(l+1, i-1, s1);
		}
	}
	dp[l][r] = res;
	return res;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> s;
	cout << calc(0, n-1) << '\n';
//	for(int l = 0;l < n; l++){
//		for(int r = l; r < n; r++){
//			cout << l << " " << r << " = " << dp[l][r] << '\n';
//		}
//	}
	
	return 0;
}

