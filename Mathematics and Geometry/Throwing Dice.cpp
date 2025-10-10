#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
int n = 6, m = 6;
vector< vector<int> > X(n, vector<int>(m, 0));
vector< vector<int> > diag(n, vector<int>(m, 0));
vector< vector<int> > mult(vector< vector<int> > a, vector< vector<int> > b){
	vector< vector<int> > ans(n, vector<int>(m, 0));
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			for(int k = 0;k < n; k++){
				ans[i][j]+= (b[i][k] * a[k][j]) % INF;
				ans[i][j]%= INF;
			}
		}
	}
	return ans;
	
}
 
 
vector< vector<int> > binpow(vector< vector<int> > a, int bin){
	if(bin == 0){
		return diag;
	}else if(bin % 2 == 0){
		vector< vector<int> > b(n, vector<int>(m, 0));
		b = binpow(a, bin / 2);
		return mult(b, b); 
	}else{
		vector< vector<int> > b(n, vector<int>(m, 0));
		b = binpow(a, bin-1);
		return mult(b, X);
	}
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			if(i == j) diag[i][j] = 1;
		}
	}
	for(int j = 0;j < m; j++){
		X[n-1][j] = 1;
	}
	X[0][1] = 1; X[2][3] = 1; 
	X[1][2] = 1; X[3][4] = 1; X[4][5] = 1;
	vector< vector<int> > ans;
	ans= binpow(X, N);
	// for(int i = 0;i < n; i++){
		// for(int j = 0;j < m; j++){
			// cout << ans[i][j] << " ";
		// }
		// cout << endl;
	// }
// 	
 
	cout << ans[5][5] % INF;
	return 0;
}