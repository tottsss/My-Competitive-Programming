#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int isPair(char a, char b){
	if(a == '(' and b == ')') return 1;
	if(a == '[' and b == ']') return 1;
	if(a == '{' and b == '}') return 1;
	return 0;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector< vector<int> > dp(n+10, vector<int>(n+10,0));
	map<pair<int, int>, vector<int> > path;
	for(int len = 2;len <= n; len++){
		for(int i = 0; i + len-1 < n; i++){
			int j = i + len-1;
			if(isPair(s[i], s[j])){
				if(dp[i][j] < dp[i+1][j-1] + 2){
					path[{i,j}] = path[{i+1, j-1}];
					path[{i,j}].push_back(i);
					path[{i,j}].push_back(j);
					dp[i][j]=dp[i+1][j-1]+2;
				}
			}
			for(int k = i; k < j; k++){
				if(dp[i][j] < dp[i][k] + dp[k+1][j]){
					path[{i, j}] = path[{i,k}];
					for(int x : path[{k+1,j}]){
						path[{i,j}].push_back(x);
					}
					dp[i][j] = dp[i][k]+dp[k+1][j];
				}
			}
		}
	}
	set<int> st;
	for(int x : path[{0,n-1}]){
		st.insert(x);
	}
	for(int i = 0;i < n; i++){
		if(st.count(i)) cout << s[i];
	}
	/*
	Given a string made up of round, square and curly brackets. 
	Find a subsequence of maximal length that forms the correct bracket sequence.
	*/
	return 0;
}

