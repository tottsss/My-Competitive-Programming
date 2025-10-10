// Author : Iskhak Tazhibaev
#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double) - 1.0);
const double eps = (double)1e-9;
const int INF = 1e9 + 7;
    #define ff         first
    #define ss         second
    #define ll         long long
    #define ld		   long double
    #define pb         push_back
    #define ld         long double
void usaco( string filename){
  freopen((filename+".in").c_str(), "r", stdin);
  freopen((filename+".out").c_str(), "w", stdout);
}
 
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	vector<int> dp(x + 1, 0);
	for(int i = 1;i < n + 1; i++) cin >> a[i];
	dp[0] = 1;
	for(int j = 1;j <= n; j++){
		for(int i = 1;i <= x; i++){
			if(i >=a[j] and dp[i - a[j]] != INF){
				dp[i] += dp[i - a[j]] % INF;
				dp[i]%= INF;
			}
		}
	}
	
	cout << dp[x];
}
 
signed main(int argv, char** argc){
	 //usaco();
     int _t = 1;
     //cin >> _t;
     while(_t--){
     	solve();
     }
    return 0;
}