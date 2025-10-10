#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()





main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector <int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	
	function<int(vector<int>, int)> solve=[&](vector<int> v, int bit){
		if(bit < 0) return 0;
		vector<int> on, off;
		for(int x : v){
			if(x & (1<<bit)) on.push_back(x);
			else off.push_back(x);
		}	
		if(on.empty()){
			return solve(off, bit-1);
		}else if(off.empty()){
			return solve(on, bit-1);
		}else{
			return min(solve(on, bit-1), solve(off, bit-1)) + (1<<bit);
		}
	};
	
	
	cout << solve(a, 30);
	return 0;
}

