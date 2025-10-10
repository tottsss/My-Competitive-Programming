#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
int D;
void add_self(int &a, int b){
	a+= b;
	if(a < 0) a+= mod;
	if(a >= mod) a-= mod;
}
// dp[sum by module][small_already]

int calc(string s){
	int n = s.size();
	vector< vector<int> > dp(D, vector<int>(2, 0));
	int all = 0;
	dp[0][0] = 1;
	for(int i = 0;i < n; i++){
		vector< vector<int> > new_dp(D, vector<int>(2, 0));
		for(int sum = 0; sum < D; sum++){
			for(int d = 0;d < 10; d++){
				for(int f : {0, 1}){
					if(!f and d > (s[i]-'0')) continue;
					add_self(new_dp[(sum + d) % D][(f || d < (s[i]-'0'))], dp[sum][f]);
				}
			}
		}
		dp = new_dp;
	} 
	all = dp[0][1] + dp[0][0];
	add_self(all, -1);
	return all;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	cin >> D;
	cout << calc(s);
	return 0;
}

