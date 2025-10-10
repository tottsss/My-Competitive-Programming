#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<int> a(n);
	map<int, int> cnt;
	for(auto &i : a){
		cin >> i;
		cnt[i]++;
	}
	while(q--){
		int x, y; cin >> x >> y;
		cout << n - cnt[x] - (y != x ? cnt[y] : 0) << '\n';
	}
	

	return 0;
}
