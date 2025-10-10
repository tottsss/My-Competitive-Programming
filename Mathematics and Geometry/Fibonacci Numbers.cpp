#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
vector< vector<int> > X(2, vector<int>(2, 0));
 
vector< vector<int> > mult(vector< vector<int> > a, vector< vector<int> > b){
	vector< vector<int> > ans(2, vector<int>(2, 0));
	for(int i = 0;i < 2; i++){
		for(int j = 0;j < 2; j++){
			for(int k = 0;k < 2; k++){
				ans[i][j]+= a[i][k] * b[k][j];
				ans[i][j]%= INF;
			}
		}
	}
	return ans;
	
}
 
 
vector< vector<int> > binpow(vector< vector<int> > a, int n){
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}else if(n % 2 == 0){
		vector< vector<int> > b(2, vector<int>(2, 0));
		b = binpow(a, n / 2);
		return mult(b, b); 
	}else{
		vector< vector<int> > b(2, vector<int>(2, 0));
		b = binpow(a, n-1);
		return mult(b, X);
	}
}
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	X[0][0] = 0; 
	X[1][1] = 1; 
	X[0][1] = 1; 
	X[1][0] = 1;
	vector< vector<int> > ans = binpow(X, n);
	cout << ans[1][0] % INF;
	return 0;
}