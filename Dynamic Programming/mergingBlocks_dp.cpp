#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int n;
int a[100], b[100], dp[100][100], used[100][100];
pair<int, int> last[100][100];



pair<int, int> merge(pair<int, int> &A, pair<int, int> &B){
	return {A.ff, B.ss};
}

int f(int l, int r){
	if(l > r) return 0;
	if(l == r){
		last[l][r] = {a[l], b[l]};
		used[l][r] = 1;
		return dp[l][r] = 0;
	}
	if(used[l][r]) return dp[l][r];
	dp[l][r] = INT_MAX;
	for(int k = l;k < r; k++){
		int s = f(l, k) + f(k+1, r);
		pair<int, int> A = last[l][k];
		pair<int, int> B = last[k+1][r];
		s+= A.ff*B.ss;
		if(s < dp[l][r]){
			dp[l][r] = s;
			last[l][r] = merge(A, B);
		}		
	}
	used[l][r] = 1;
	return dp[l][r];
}
//https://acmp.ru/index.asp?main=task&id_task=553
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i] >> b[i];
	}
	cout << f(0, n-1);
	return 0;
}

