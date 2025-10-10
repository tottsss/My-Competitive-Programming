#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e4;

int num[10] = {0,2,5,5,4,5,6,3,7,6};
int n, m;

struct node{
	int cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int sum=0;
};
node dp[10][N+10];
node umax(node a, node b){
	if(a.sum != b.sum){
		if(b.sum > a.sum)return b;
		return a;
	}
	for(int i = 9;i >= 1; i--){
		if(b.cnt[i] > a.cnt[i]){
			return b;
		}else if(a.cnt[i] > b.cnt[i]) return a;
	}
	return a;
}
// atcoder beginner 118 D
void print(node ans){
	for(int i = 9;i >= 1; i--){
		for(int j = 1;j <= ans.cnt[i]; j++) cout << i;
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int a[m + 1];
	for(int i = 1;i <= m; i++){
		cin >> a[i];
	}
	for(int j = 0;j <= m; j++){
		for(int w = 0; w <= n; w++){
			dp[j][w].sum = INT_MIN;
		}
	}
	dp[0][0].sum = 0;
	node ans;
	for(int i = 1;i <= m; i++){
		for(int w = n; w >= 0; w--){
			dp[i][w] = umax(dp[i][w], dp[i-1][w]);
			for(int use = 1; w - use * num[a[i]] >= 0; use++){
				node tt = dp[i-1][w-use * num[a[i]]];
				tt.cnt[a[i]]+= use;
				tt.sum+= use;
				dp[i][w] = umax(dp[i][w], tt);
			}
		}
	}
	print(dp[m][n]);
	return 0;
}

