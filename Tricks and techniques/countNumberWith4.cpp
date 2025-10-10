#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;

int dp[20], ten[20];
int rec(int n){
	if(n < 4) return 0;
	int lg = 0, x = n / 10;
	while(x > 0){
		lg++, x/= 10;
	}	
	for(int i = 1;i <= lg; i++){
		if(i == 1) dp[i] = 1;
		else{
			dp[i] = dp[i-1] * 9 + ten[i-1];	
		}
	}
	int one = n / ten[lg];
	if(one >= 4){
		if(one == 4) return (one * dp[lg]) + (n%ten[lg])+1;
		else return (ten[lg] + ((one-1) * dp[lg]) + rec(n%ten[lg]));
	}else{
		return (one * dp[lg] + rec(n%ten[lg]));
	}
}


void solve(){
	int k; cin >> k;
//	cout << rec(k);
	if(k < 4){
		cout << k;
	}else if(k == 4) cout << 5;
	else{
		int l = 0, r = (int)1e17;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			if(mid-rec(mid) >= k) r = mid;
			else l = mid;
		}
		cout << r;
	}
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T = 1;
	ten[0] = 1;
	for(int i = 1;i <= 18; i++){
		T*= 10;
		ten[i] = T;
	}
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
