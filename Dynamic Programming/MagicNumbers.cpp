#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
int m, d; 


int add_self(int &a, int b){
	a+= b;
	if(a < 0) a+= mod;
	if(a >= mod) a-= mod;
}

int calc(string s){
	vector< vector<int> > dp(m, vector<int>(2, 0));
	dp[0][0] = 1;
	int ans = 0;
	for(int len = 1; len <= s.size(); len++){
		vector< vector<int> > new_dp(m, vector<int>(2, 0));
		for(int sum = 0; sum < m; sum++){
			if(len % 2==0){
				for(int f : {0, 1}){
					if(!f and d > (s[len-1]-'0')) continue;
					add_self(new_dp[(sum*10+ d) % m][(f || (s[len-1]-'0')>d)], dp[sum][f]);
				}
			}else{
				for(int dig = 0; dig < 10; dig++){
					if(dig == d) continue;
					for(int  f : {0, 1}){
						if(!f and dig > (s[len-1]-'0')) continue;
						add_self(new_dp[(sum*10 + dig) % m][(f || (s[len-1]-'0')>dig)], dp[sum][f]);
					}
				}
			}	
		}
		dp = new_dp;
//		ans =(a	ns + dp[0][1] + dp[0][0]) % mod;
	}
	ans =(ans + dp[0][1] + dp[0][0]) % mod;
	return ans;
}

int calc1(string s){
	vector< vector<int> > dp(m, vector<int>(2, 0));
	dp[0][0] = 1;
	int ans = 0;
	for(int len = 1; len <= s.size(); len++){
		vector< vector<int> > new_dp(m, vector<int>(2, 0));
		for(int sum = 0; sum < m; sum++){
			if(len % 2==0){
				for(int f : {0, 1}){
					if(!f and d > (s[len-1]-'0')) continue;
					add_self(new_dp[(sum*10+ d) % m][(f || (s[len-1]-'0')>d)], dp[sum][f]);
				}
			}else{
				for(int dig = 0; dig < 10; dig++){
					if(dig == d) continue;
					for(int  f : {0, 1}){
						if(!f and dig > (s[len-1]-'0')) continue;
						add_self(new_dp[(sum*10 + dig) % m][(f || (s[len-1]-'0')>dig)], dp[sum][f]);
					}
				}
			}	
		}
		dp = new_dp;
//		ans =(a	ns + dp[0][1] + dp[0][0]) % mod;
	}
	ans =(ans + dp[0][1]) % mod;
	return ans;
}
// https://codeforces.com/problemset/problem/628/D?locale=en

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> m >> d;
	string a, b; cin >> a >> b;
	int ans = 0;
	add_self(ans, calc(b));
	add_self(ans, -calc1(a));
	cout << ans;

	return 0;
}

