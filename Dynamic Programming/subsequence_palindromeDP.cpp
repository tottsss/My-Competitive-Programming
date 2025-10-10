#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int dp[40][40];
int n;
string s;
//https://acmp.ru/index.asp?main=task&id_task=481

int f(int l, int r){
	if(l > r) return 0;
	if(l == r) return dp[l][r] = 1;
	if(dp[l][r] != -1) return dp[l][r];
	if(s[l] == s[r]){
		return dp[l][r] = f(l+1, r) + f(l, r-1)+1;
	}else{
		return dp[l][r] = f(l+1, r) + f(l, r-1) - f(l+1, r-1);
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	cout << f(0, n-1);

	return 0;
}

