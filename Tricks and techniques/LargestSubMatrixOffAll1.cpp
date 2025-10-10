#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5000;

int dp[N][N];
int n, m;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			char c; cin >> c;
			if(j == 0){
				dp[i][j] = (c == '1' ? 1 : 0);
			}else{
				dp[i][j] = (c == '1' ? dp[i][j-1] + 1 : 0);
			}
		}
	}
	int MAX = 0;
	for(int j = 0;j < m; j++){
		vector<int> row;
		for(int i = 0;i < n; i++){
			row.push_back(dp[i][j]);
		}
		sort(all(row));
		for(int i = 0;i < n; i++){
			MAX = max(MAX, (n-i) * row[i]);
		}
	}
	cout <<MAX;
	return 0;
}

