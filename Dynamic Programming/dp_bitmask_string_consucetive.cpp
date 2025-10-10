#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
int M = 1e9;
int cons(int mask, int len){
	int c = 0;
	for(int i = 0;i < len; i++){
		if(mask & (1<<i)){
			c++;
			if(c > 2) return 0;
		}else{
			c = 0;
		}
	}
	return 1;
}
void print(int mask){
	for(int i = 0;i < 8; i++){
		if(mask&(1<<i)) cout << 1;
		else cout << 0;
	}
}

int get(char c){
	return (c-'a'+1);
}
// https://constructor2023.contest.codeforces.com/group/sVRDLercWX/contest/431163/problem/H
void solve(){
	string s; cin >> s;
	int n = s.size();
	vector< vector<int> > dp(n, vector<int>((1<<7), -M));
	dp[0][1] = s[0]-'a'+1;
	dp[0][0] = 0;
	for(int i = 1;i < n; i++){
		if(i-6 <= 0){
			for(int mask = 0;mask < (1<<(i+1)); mask++){
				int c = 0;
				if(__builtin_popcount(mask) > 3) continue;
				if(!cons(mask, 7)) continue;
				for(int j = 0;j < i+1; j++){
					if(mask & (1<<j)){
						c+= get(s[j]);
					}
				}
				dp[i][mask] = max(dp[i][mask], c); 
			}
		}else{
			for(int before = 0; before < (1<<7); before++){
				if( __builtin_popcount(before) > 3) continue;
				if(!cons(before, 7)) continue;
				int mask=0;
				for(int j = 0;j < 7; j++){
					if(before&(1<<(j+1))){
						mask+=(1<<j);
					}
				}
				dp[i][mask] = max(dp[i][mask], dp[i-1][before]);
				if(mask&(1<<6)) assert(false);
				mask+= (1<<6);
				if(!cons(mask, 7)) continue;
				if(__builtin_popcount(mask) > 3) continue;
				dp[i][mask] = max(dp[i][mask], dp[i-1][before] + get(s[i]));
			}
		}
	}
	
	
	int mx = 0;
	for(int mask = 0; mask < (1<<7); mask++){
		
		mx = max(mx, dp[n-1][mask]);
	}
	cout << mx;
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
