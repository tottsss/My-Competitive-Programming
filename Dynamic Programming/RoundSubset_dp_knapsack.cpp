#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int n, k;
int five[205], two[205];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n; i++){
		int x; cin >> x;
		while(x > 1 and x%2==0){
			two[i]++, x/= 2;
		}
		while(x > 1 and x%5==0){
			five[i]++, x/= 5;
		}
	}
	//If i'm at index i then dp[chosen][fives] = the max power of 2 in the product of numbers in subset of size chosen 
	// having power of 5 as fives in the array [1,i].
	vector< vector<int> > dp(205, vector<int>(6001, INT_MIN));
	//Only this subset exists initially (Subset of size 0 has power of 2 = 0 , power of 5 = 0)
	dp[0][0] = 0;
	for(int i = 1;i <= n; i++){
		for(int chosen = k; chosen >= 1; chosen--){
			for(int fives = 6000; fives >= five[i]; fives--){
				/*
				if a subset dp[chosen-1][fives-five[i]] exists,
				then check whether adding the current number to this subset give more power of 2 
				(dp[chosen+1][fives+five[i]]) than what was previously found and update it accordingly.
				*/
				dp[chosen][fives] = max(dp[chosen][fives], dp[chosen-1][fives-five[i]] + two[i]);
			}
		}
	}
	int mx = 0;
	for(int fives = 0; fives <= 6000; fives++){
		// power of 10 is the min( power of 2 and power of 5)
		mx = max(mx, min(fives, dp[k][fives]));
	}
	cout << mx;
	return 0;
}

