#include <bits/stdc++.h>
using namespace std;
#define int long long 
main(){
	int n, x;
	cin >> n;
	map<int, int> mp;
	mp[0LL] = 1LL;
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	int cursum = 0LL;
	int cnt = 0LL;
	for(int i = 0;i < n; i++){
		cursum+= a[i];
		mp[(cursum % n + n) % n]++;
	}
	for(auto x : mp){
		cnt+= x.second * (x.second -1)/ 2;
	}
	cout << cnt;
	return 0;
}