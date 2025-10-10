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
	int n, c; cin >> n >> c;
	int t[n], p[n];
	for(int i = 0;i < n; i++){
		cin >> t[i] >> p[i];
	}
	vector<int> ans(n, c);
	for(int bit = 0; bit < 30; bit++){
		int one = 1, zero = 0, cur = (c >> bit) & 1;
//		int cc = cur;
		for(int i = 0;i < n; i++){
			int p_bit = ((p[i]>>bit)&1);
			int cc = cur;
			if(t[i] == 1){
				one = (one & p_bit);
				zero = (zero &  p_bit);
				cur = (cur & p_bit);
			}
			if(t[i] == 2){
				cur = (cur | p_bit);
				one = (one | p_bit);
				zero = (zero | p_bit);
			}
			if(t[i] == 3){
				cur = (cur ^ p_bit);
				one = (one ^ p_bit);
				zero = (zero ^ p_bit);
			}
			if(((ans[i]>>bit)&1) == 1){
				
				ans[i]|= (one<<bit);
			}else ans[i]|= (zero<<bit);
		}
	}
	
	for(int x : ans) cout << x << ' ';
	return 0;
}

