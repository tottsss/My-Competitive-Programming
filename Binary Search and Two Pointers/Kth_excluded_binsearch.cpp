#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


// https://atcoder.jp/contests/abc205/tasks/abc205_d
/*
K_th Exlucded
You are given a sequence of N positive integers: A=(A1​,A2​,…,AN​), and
Q queries.
In the
i-th query (1≤i≤Q), given a positive integer Ki​, 
find the Ki​-th smallest integer among the positive integers that differ from all of A1​,A2​,…,AN​.

*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	while(q--){
		int k; cin >> k;
		int lower = upper_bound(a, a + n, k) - a;
		int l = 0, r = (int)1e18 + (int)1e6;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			lower = upper_bound(a, a + n, mid) - a;
			if(mid-lower >= k) r = mid;
			else l = mid;
		}
		cout << r << '\n';
	}
	return 0;
}

