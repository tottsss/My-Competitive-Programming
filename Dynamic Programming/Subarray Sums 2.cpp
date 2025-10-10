#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x; cin >> x;
	int a[n];
	int cursum = 0;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int S = 0;
	map<int, int> mp;
	mp[0] = 1;
	for(int i = 0;i < n; i++){
		cursum+= a[i];
		S+= mp[cursum-x];
		mp[cursum]++;
	}
	cout << S;
	return 0;
}