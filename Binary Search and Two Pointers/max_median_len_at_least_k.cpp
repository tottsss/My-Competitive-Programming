#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n), pref(n), c(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	if(k == 1){
		cout << *max_element(all(a));
		return 0;
	}
	function<int(int)> good=[&](int m){
		for(int i = 0;i < n; i++){
			if(a[i] >= m) c[i] = 1;
			else c[i] = -1;
		}
		pref[0] = c[0];
		for(int i = 1;i < n; i++) pref[i] = pref[i-1] + c[i];
		set<int> st;
		int sum = pref[k-1]; 
		st.insert(0);
		for(int i = k; i < n; i++){
			if(sum -  *st.begin() > 0) return 1;
			sum+= c[i];
			st.insert(pref[i-k]);
		}
		if(sum-*st.begin() > 0) return 1;
		return 0;
	};
	
	int l = 0, r = (int)2e5 + 10;
	while(l + 1 < r){
		int mid = (l + r)>>1;
		if(good(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
//	cout << good(l) << '\n';
	
	cout << l;
	return 0;
}

