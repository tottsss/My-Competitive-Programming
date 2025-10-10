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
	vector<int> s(n);
	map<int, vector<int> > mp;
	for(int i = 0;i < n; i++){
		cin >> s[i];
		mp[s[i]].push_back(i);
	}
	
	function<int(int, int, int)> get=[&](int l, int r, int type){
		if(l > r) return 0LL;
		int L = lower_bound(all(mp[type]), l) - mp[type].begin();
		int R = upper_bound(all(mp[type]), r)-mp[type].begin();
		return R-L;	
	};
	int subs = 0;
	for(int i = 1;i <= n; i++){
		subs+= ((i / 2)*(n-i+1));
	}
	for(int i = 0;i < n/2; i++){
		int idx = n-1-i;
		int s2 = i+1, s1 = get(i+1, idx, s[i]);
		subs-= s1*s2;
	}
	// https://atcoder.jp/contests/abc290/tasks/abc290_e
	mp.clear();
	reverse(all(s));
	for(int i = 0;i < n; i++){
		mp[s[i]].push_back(i);
	}
	function<int(int, int, int)> get1=[&](int l, int r, int type){
		if(l > r) return 0LL;
		int L = lower_bound(all(mp[type]), l) - mp[type].begin();
		int R = upper_bound(all(mp[type]), r)-mp[type].begin();
		return R-L;	
	};
	for(int i = 0;i < n/2; i++){
		int idx = n-1-i;
		int s2 = i+1, s1 = get(i+1, idx-1, s[i]);
		subs-= s1*s2;
	}
	cout << max(0LL, subs);
	return 0;
}