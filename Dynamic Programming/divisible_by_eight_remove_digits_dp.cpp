#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int num(char x){
	return (x-'0');
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	s = string(1, '#') + s;
	vector< vector<int> > dp(n+2, vector<int>(8, 0)), p(n+2, vector<int>(8, -1));
	for(int i = 1;i <= n; i++){
		dp[i][num(s[i])%8]=1;
		if(i == n) continue;
		for(int j = 0;j < 8; j++){
			if(dp[i][j] == 1){
				dp[i+1][j] = 1;
				p[i+1][j] = j;
				dp[i+1][(j * 10 + num(s[i+1]))%8] = 1;
				p[i+1][(j * 10 + num(s[i+1]))%8] = j;
			}
		}
	}
	if(dp[n][0] == 0){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	string ans = "";
	int N = n, M = 0;
	while(M != -1 and N > 0 and dp[N][M]){
		if(p[N][M] != M){
			ans.push_back(s[N]);
		}
		M = p[N][M], N--;
	}
	reverse(all(ans));
	cout << ans;
	return 0;
}

