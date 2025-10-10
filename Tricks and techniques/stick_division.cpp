#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int x, n; cin >> x >> n;
	vector<int> a(n);
	for(auto &e : a) cin >> e;
	multiset<int> st(all(a));
	int ans = 0;
	while(st.size() > 1){
		int beg = *st.begin();
		st.erase(st.begin());
		ans+= beg;
		int beg1 = *st.begin();
		st.erase(st.begin());
		ans+= beg1;
		st.insert(beg + beg1);
	}
	cout << ans;
	return 0;
}

