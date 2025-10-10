#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5 + 10;
int a[N];
int l[N], r[N], d[N];
int x[N], y[N], pref[N];
int dp[N];
int n, m, q;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m; i++){
		cin >> l[i] >> r[i] >> d[i];
	}
	
	for(int i = 1;i <= q; i++){
		cin >> x[i] >> y[i];
		pref[x[i]]++, pref[y[i] + 1]--;
	}
//	cout << "array pref = ";
	for(int i = 1;i <= m; i++){
		pref[i]+= pref[i-1];
//		cout << pref[i] << " ";
	}
//	cout << '\n';
//https://codeforces.com/contest/296/problem/C
	for(int i = 1;i <= m; i++){
		int many = pref[i];
//		cout << l[i] << ' ' << r[i] << " " << d[i] << " = " << many << '\n'; 
		dp[r[i]+1]-= many*d[i];
		dp[l[i]]+= many*d[i];
	}
	for(int i = 1;i <= n; i++){
		dp[i]+= dp[i-1];
	}
	for(int i = 1;i <= n; i++){
		cout << dp[i] + a[i] << " ";
	}
	return 0;
}

