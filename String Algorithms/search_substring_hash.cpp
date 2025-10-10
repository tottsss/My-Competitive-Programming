#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
const int P = 31;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string t; cin >> t;
	int n = s.size();
	vector<int> pw(n), pref(n);
	pref[0] = s[0]-'a', pw[0] = 1;
	for(int i = 1;i < s.size(); i++){
		pw[i] = (pw[i-1] * P) % mod;
		pref[i] = (pref[i-1] * P +  (s[i]-'a')) % mod;
	}
	int H = 0;
	for(int i = 0;i < t.size(); i++){
		H = (H * P + (t[i]-'a')) %mod;
	}
	function<int(int, int)> get=[&](int l, int r){
		if(l == 0) return pref[r];
		int S = ((pref[r] - pref[l-1] * pw[r-l+1]) %mod)+ mod;
		return S%mod;
	};
	vector<int> ans;
	for(int i = 0;i + (int)t.size()-1 < s.size(); i++){
		if(get(i, i+(int)t.size()-1) == H){
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for(int x : ans) cout << x << ' ';
	return 0;
}

