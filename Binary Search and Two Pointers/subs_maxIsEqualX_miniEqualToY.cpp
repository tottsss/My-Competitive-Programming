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
	int n, x, y; cin >> n >> x >> y;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	vector<int> v;
	function<void()> two_p = [&](){
		if(v.empty()) return;
//		for(auto k : v) cout << k << ' ';
//		cout << '\n';
		int X = 0, Y = 0;
		for(int l = 0, r = 0; l < v.size(); l++){
			
			while(r < v.size() and (X == 0 or Y == 0)){
				if(v[r] == x) X++;
				if(v[r] == y) Y++;
				r++;
			}
			if(X > 0 and Y > 0){
				ans+= (v.size() + 1 - r); 
			}
			if(v[l] == x) X--;
			if(v[l] == y) Y--;
		}
	};
	
	for(int i = 0;i < n; ){
		int j = i;
		while(j < n and (a[j] > x or a[j] < y)) j++;
		while(j < n and a[j] >= y and a[j] <= x){
			v.push_back(a[j]);
			j++;
		}
		if(v.empty() == false){
			two_p();
			v.clear();
		}
		i = j;
	}
	cout << ans;
	return 0;
}

