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
	int n; cin >> n;
	vector< pair<int, int> > a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i].ff;
		a[i].ff%= n;
		a[i].ss = i;
	}
	sort(all(a));
//	map<int, int> mp;
//	int cursum = 0;
//	mp[0] = 0;
//	for(int i = 0;i < n; i++){
//		cursum+= a[i].ff;
//		if(mp.count(cursum%n)){
//			int l = mp[cursum%n];
//			int r = i;
//			cout << r-l+1 << '\n';
//			for(int j = l;j <= r; j++){
//				cout << a[j].ss+1 << ' ';
//			}
//			return 0;
//		}
//		mp[cursum%n] = i;
//	}
	for(int i = 0;i < n; i++){
		int sum = 0;
		for(int j = i;j < n; j++){
			sum+= (a[j].ff);
			if(sum%n==0){
				cout << j-i+1 << '\n';
				for(int k = i;k <= j; k++){
					cout << a[k].ss+1 << ' ';
				}
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}

