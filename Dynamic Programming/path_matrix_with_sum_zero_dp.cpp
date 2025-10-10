#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
void solve(){
	int n; cin >> n;
	int m; cin >> m;
	vector< vector<int> > a(n, vector<int>(m));
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			cin >> a[i][j];
		}
	}
	if((n+m-1)%2){
		cout << "NO";
		return;
	}
	vector< vector<int> > mx(n, vector<int>(m,INT_MIN));
	vector< vector<int> > mn(n, vector<int>(m,INT_MAX));
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			if(i == 0 and j == 0){
				mx[i][j] = a[i][j];
				mn[i][j] = a[i][j];
			}else{
				if(i-1 >= 0){
					mx[i][j] = max(mx[i][j], mx[i-1][j] + a[i][j]);
					mn[i][j] = min(mn[i][j], mn[i-1][j] + a[i][j]);
				}
				if(j-1 >= 0){
					mx[i][j] = max(mx[i][j], mx[i][j-1] + a[i][j]);
					mn[i][j] = min(mn[i][j], mn[i][j-1] + a[i][j]);
				}
			}
		}
	}
	if(mx[n-1][m-1] < 0 or mn[n-1][m-1] > 0) cout << "NO";
	else cout << "YES";
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
