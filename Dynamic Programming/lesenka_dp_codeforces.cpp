#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int a[n], p[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	vector<int> one, zero;
	for(int i = 0;i < n-1; i++){
		if(a[i] < a[i+1]){
			p[i] = 1, one.push_back(i);
		}else if(a[i + 1] > a[i]){
			p[i] = 0, zero.push_back(i);
		}else{
			
		}
		if(a[i] <= a[i+1]){
			p[i] = 1, one.push_back(i);
		}else p[i] = 0, zero.push_back(i);
	}
	while(q--){
		int l, r; cin >> l >> r;
		l--, r-= 2;
		if(r-l+1 <= 1 or zero.empty() or one.empty()){
			cout << "Yes" << '\n';
			continue;
		}
		int ZERO = lower_bound(all(zero), l) - zero.begin();
		int ONE = upper_bound(all(one), r) - one.begin();
		ONE--;
		if(ONE >= 0 and ONE < one.size() and one[ONE] >= l and one[ONE] <= r){
			if(ZERO >= 0 and ZERO < zero.size() and zero[ZERO] >= l and zero[ZERO] <= r){
				if(zero[ZERO]==one[ONE]) assert(false);
				if(zero[ZERO] > one[ONE]) cout << "Yes";
				else cout << "No";
				cout << '\n';
			}else cout << "Yes" << '\n';
		}else cout << "Yes" << '\n';
	}
	return 0;
}

