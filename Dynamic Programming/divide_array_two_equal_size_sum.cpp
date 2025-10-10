#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

short dp[101][51][5001];
int a[101], used[101];
int n, elem;


void f(int need){
	if(elem > n/2 or need < 0) return;
	if(elem == n/2){
		if(need == 0){
			for(int i = 1;i <= n; i++){
				if(used[i]) cout<< i << ' ';
			}
			cout << '\n';
			for(int i = 1;i <= n; i++) if(!used[i]) cout << i << ' ';
			exit(0);
		}
		return;
	}
	for(int i = 1;i <= n; i++){
		if(used[i] == 0){
			used[i] = 1, elem++;
			f(need-a[i]);
			elem--, used[i] = 0;
		}
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	int sum = 0;
	a[0] = INT_MAX;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum+= a[i];
	}
	if(!(sum%2) and !(n%2)){
		memset(dp, -1, sizeof(dp));
		dp[0][0][0] = 0;
		for(int i = 1;i <= n; i++){
			for(int s = 0; s <= sum/2; s++){
				for(int el = 0; el <= i && el <= n / 2; el++){
					if(dp[i-1][el][s] != -1 and dp[i][el][s] == -1) dp[i][el][s] = dp[i-1][el][s];	
		if(s >= a[i] and el > 0 and dp[i-1][el-1][s-a[i]] != -1 and 
			(dp[i][el][s] == -1 or dp[i][el][s] >1+ dp[i-1][el-1][s-a[i]]))
						 dp[i][el][s] =dp[i-1][el-1][s-a[i]] + 1;
				}
			}
		}
		if(dp[n][n/2][sum/2] != -1){
			set<int> p;
			int i = n, j = n/2, k = sum / 2;
			while(true){
				if(i == 0 or j<=0 or k <= 0) break;
				if(i > 0 and j > 0 and k >= a[i]){
					if(dp[i][j][k] > dp[i-1][j-1][k - a[i]] and dp[i-1][j-1][k-a[i]] != -1){
						p.insert(i);
						k-= a[i];
						i--, j--;
					}
				}
				if(i > 0){
					if(dp[i][j][k] == dp[i-1][j][k]) i--;
				}
			}
			for(int x : p) cout << x << ' ';
			cout << '\n';
			for(int i = 1;i <= n; i++) if(p.count(i)==false) cout << i << ' ';
			return 0;
		}
	}
	cout << "No solution";
	return 0;
}
