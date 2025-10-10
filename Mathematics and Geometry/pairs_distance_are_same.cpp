#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, int> x, y;
	map<pair<int, int>, int> same;
	int ans = 0;
	for(int i = 0;i < n; i++){
		int a, b; cin >> a >> b;
		ans+= x[a] + y[b] - same[{a,b}];
		x[a]++, y[b]++, same[{a,b}]++;
	}
	cout << ans;
	return 0;
}

