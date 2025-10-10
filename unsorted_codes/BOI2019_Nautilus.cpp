#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 500;
const int SZ = (N + 2) * (N + 2);
bitset<SZ> dp[5001];
	bitset<SZ> cant;
int n, m, q;
char a[555][555];
int num[555][555], T;
string s;
int in(int i, int j){
	return (i >= 1 && j >= 1 && i <= n && j <= m and a[i][j] == '.');
}
map<char, vector<pair<int, int> > > dir;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	
	for(int i = 0;i <= n + 1; i++){
		for(int j = 0;j <= m+1; j++){
			if(i >= 1 && j >= 1 && i <= n && j <= m) cin >> a[i][j];
			else a[i][j] = '#';
			num[i][j] = T++;
			if(a[i][j] == '#') cant[num[i][j]] = 1;
			else dp[0][num[i][j]] = 1;
		}
	}
	dir['N'].push_back({-1, 0});
	dir['S'].push_back({1, 0});
	dir['E'].push_back({0, 1});
	dir['W'].push_back({0, -1});
	dir['?'].push_back({-1, 0});
	dir['?'].push_back({1, 0});
	dir['?'].push_back({0, 1});
	dir['?'].push_back({0, -1});
	
	cin >> s;
	s = "#" + s;
	for(int round = 1; round <= q; round++){
		char ch = s[round];
		bitset<SZ> new_dp;
//		if(ch == 'N'){
//			new_dp = dp[0] & (new_dp >> (m + 2));
//		}else if(ch == 'S'){
//			new_dp = dp[0] & (new_dp << (m + 2));
//		}else if(ch == 'E'){
//			new_dp = dp[0] & (new_dp << 1);
//		}else if(ch == 'W'){
//			new_dp = dp[0] & (new_dp >> 1);
//		}else{
//			new_dp = (new_dp >> 1) | (new_dp << 1) | (new_dp << (m + 2)) | (new_dp >> (m + 2));
//			new_dp = (new_dp & dp[0]);
//		}
		for(auto [x, y] : dir[ch]){
			int k = x * (m + 2) + y;
			if(k < 0){
				k = -k;
				new_dp |= (dp[round-1]>>k);
			}else new_dp |=(dp[round-1] << k);
		}
		dp[round] = (new_dp & dp[0]);
	}
	cout << dp[q].count();
	return 0;
}