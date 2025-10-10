#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++) cin >> a[i];
	sort(a, a + n);
	int sz = n * (n-1) / 2;
	vector<int> st;
	function<int(int)> check=[&](int m){
		int smaller = 0;
		for(int i = 0;i < n; i++){
			int L = lower_bound(all(st), a[i]-m) - st.begin();
			int R = upper_bound(all(st), a[i]+m) - st.begin();
			smaller+= (R-L);
			st.push_back(a[i]);
		}
		st.clear();
		return smaller;
	};
	int l = -1, r = (int)1e9;
	for(int round = 1; round <= 35 and r > l; round++){
		int mid = (l + r)>>1;
		if(check(mid) >= ((sz + 1)/2)) r = mid;
		else l = mid;
	}

	cout << r;
	return 0;
}

