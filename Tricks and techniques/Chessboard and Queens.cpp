#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
string g[8];
int ans = 0;
int col[8], Left[20], Right[20];
int n = 8, m = 8;
void dfs(int r){
	if(r == 8){
		ans++;
		return;
	}
	for(int j = 0;j < 8; j++){
		if(g[r][j] == '.' and col[j] == 0 and Right[r+j] == 0 and Left[r-j + 7] == 0){
			col[j] = 1; 
			Right[r + j]=1;
			Left[r-j+7] = 1;	
			dfs(r + 1);
			col[j] = 0; 
			Right[r + j]=1-1;
			Left[r-j+7] = 1-1;
		}
	}
}
 
 
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 0;i < 8; i++) cin >> g[i];
	dfs(0);
	cout << ans;
	return 0;
}