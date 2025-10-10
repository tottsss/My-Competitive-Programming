#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


// https://atcoder.jp/contests/arc114/tasks/arc114_a
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++) cin >> a[i];
	int answer = -1;
	vector<int> prime;
	for(int j = 2;j <= 50; j++){
		int ok = 1;
		for(int k = 2; k * k <= j; k++){
			if(j%k==0){
				ok = 0;
				break;
			}
		}
		if(ok) prime.push_back(j);
	}
	/*
	Given are N integers between 2 and 50 (inclusive): X1?,X2?,?,XN?. 
	Find the minimum positive integer Y that satisfies the following for every

i=1,2,?,N:

Xi? and Y are not coprime.
	*/
	for(int mask = 1; mask < (1<<(int)prime.size()); mask++){
		int p = 1, ok = 1;
		for(int i = 0;i < prime.size(); i++){
			if(mask & (1<<i)){
				p*= prime[i];
			}
		}
		for(int i = 0;i < n; i++){
			if(__gcd(a[i], p) == 1){
				ok = 0;
				break;
			}
		}
		if(ok){
			if(answer == -1 or answer > p) answer = p;
		}
	}
	cout << answer;
	return 0;
}

