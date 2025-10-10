#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
// D = -1
// R = -2

int n, q;
vector< vector<int> > a(1600, vector<int>(1600));
vector< vector<int> > dp(1600, vector<int>(1600, 0));
void to_move(int &i,int &j, int x){
	if(x == -1) i++;
	else j++;
}
int calc(int i, int j){
//	cout << i+1 << ' ' << j+1 << '\n';
	if(i == n and j == n) return 0;
	if(i == n or j == n){
		dp[i][j] = a[i][j];
		return dp[i][j];
	}
	if(dp[i][j] > 0) return dp[i][j];
	int ni = i, nj = j;
	to_move(ni, nj, a[i][j]);
	dp[i][j] = calc(ni, nj);
	return dp[i][j];	
}
int sum(){
	return calc(0, 0);
}
void path_to_zero(int i, int j){
	if(i < 0 or j < 0) return;
	dp[i][j] = 0;
	int ni = i, nj = j;
	if(j > 0){
		if(a[i][j-1] == -2){
			path_to_zero(i, j-1);
		}
	}
	if(i > 0){
		if(a[i-1][j] == -1){
			path_to_zero(i-1, j);
		}
	}
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i <= n; i++){
		if(i == n){
			for(int j = 0;j < n; j++){
				cin >> a[i][j];
			}
		}else{
			for(int j = 0;j <= n; j++){
				if(j == n){
					cin >> a[i][j];
				}else{
					char c; cin >> c;
					if(c == 'D') a[i][j] = -1;
					else a[i][j] = -2;
				}
			}
		}
	}
	cout << sum() << '\n';
	cin >> q;
	while(q--){
		int x, y; cin >> x >> y; x--, y--;
		path_to_zero(x, y);
		if(a[x][y] == -1){
			a[x][y] = -2;
		}else{
			a[x][y] = -1;
		}		
		cout << sum() << '\n';
	}
	return 0;
}