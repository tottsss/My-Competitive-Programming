#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;

int sum(int n){
	if(n <= 0) return 0;
	return (n * (n + 1)) / 2;
}

int range(int l, int r){
	return sum(r) - sum(l-1);
}

void solve(){
	int n, k; cin >> n >> k;
	if(k <= n){
		int all = sum(k-1) - sum(k/2 - 1)*2;
		if(k % 2 == 1) all-= (k / 2);
		cout << all;
	}else{
		if(n <= k / 2){
			cout << sum(n);
		}else{
//			https://codeforces.com/group/PEvPpnaSkv/contest/463799/problem/F
			int ans = 0;
			if(k % 2 == 1){
				ans-= (n - (k + 1) / 2 + 1);
				k++;
			}
			      ans += sum(k / 2) + (k / 2) * (n - k/ 2) - sum(n - k /2 );
			
			cout << ans;
		}
	}
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
