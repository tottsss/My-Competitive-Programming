#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
void solve(){
	int n; cin >> n;
	vector<int> a(n), mp(n+1,0);
	multiset<int> st;
	int ready = -1;
	st.insert((int)1e9);
	long long ans = 0;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		st.insert(a[i]);
		mp[a[i]]++;
	}
	for(int need = 0; need <= n; need++){
		if(ans < 0){
			cout << -1 << ' ';
			continue;
		}
		auto it2 = st.upper_bound(ready);
		if(it2!=st.end()){
			for(int it = *it2; it < need; it++){
				if(ready+1==it and st.count(it)){
					ready++;
					mp[it]--;
					st.erase(st.find(it));
				}else break;	
			}
		}
		for(int it = ready+1; it < need; it++){
			if(st.size()==1){
				ans = (int)-1e9;
				break;
			}
			auto it1 = st.lower_bound(it);
			if(it1!=st.begin())
			it1--;
			int beg = *it1;
			if(beg > it){
				ans = (int)-1e9;
				break;
			}
			ans+= it-beg;
			mp[beg]--;
			st.erase(it1);
			ready++;
		}
		long long ct = max(-1LL, ans+mp[need]);
		cout << ct << " ";
	}
	// CF problem 1619E
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
