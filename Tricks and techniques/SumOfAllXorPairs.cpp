#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int sum = 0;
	for(int j = 0; j < 60; j++){
		int zero = 0, one = 0;
		long long pw = (1ll<<j);
		for(int i = 0;i < n; i++){
			if(a[i]&pw) one++;
			else zero++;
		}
		int s = ((one * zero)%M * (pw%M))%M;
		sum = (sum + s)%M;
	}
	cout << sum;
	return 0;
}

