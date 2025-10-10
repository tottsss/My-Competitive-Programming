#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int l = 0;
	int r = 1;
	function <bool(int)> good = [&](int m){
		int sum = 0;
		for(int i = 0;i < n; i++){
			sum+= (m / a[i]);
		}
		return sum >= x;
	};
	while(!good(r)){
		r<<=1;
	}
	r<<=1;
	while(r > l+1){
		int m = l + (r - l) /2;
		if(good(m)) r = m;
		else l = m;
	}
	cout << r;
	return 0;
}