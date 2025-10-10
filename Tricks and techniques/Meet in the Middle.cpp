#include "bits/stdc++.h"
using namespace std;
#define int long long
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, S = 0; cin >> n >> x;
	int a[n];
	for(int i = 0;i < n; i++) cin >> a[i];
	map<int, int> mp;
	vector<int> left, right;
	int mid = n /2;
	for(int mask = 0; mask < (1 << mid); mask++){
		int sum = 0;
		for(int i = 0;i < mid; i++){
			if(mask & (1 << i)){
				sum+= a[i];
			}
		}
		left.push_back(sum);
	}
	for(int mask = 0; mask < (1 << (n - mid)); mask++){
		int sum = 0;
		for(int i = 0;i < min(n, 32LL); i++){
			if(mask & (1 << i)){
				sum+= a[mid+i];
			}
		}
		right.push_back(sum);
	}
	sort(right.begin(), right.end());
	for(auto to : left){
		S+= upper_bound(right.begin(), right.end(), x-to) - lower_bound(right.begin(), right.end(), x-to);
	}
	cout << S;
	return 0;
}