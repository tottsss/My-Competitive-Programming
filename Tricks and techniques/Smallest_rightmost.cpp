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
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	vector<int> idx(n,-1);
	set< pair<int, int> > st;
	for(int i = 0;i < n; i++){
		st.insert({a[i], i});
	}
	for(int i = n-1;i >= 0; i--){
		st.erase({a[i], i});
		int del = 0;
		for(auto it = st.upper_bound({a[i], i}); it != st.end(); it++){
			idx[it->ss] = abs(it->ss-i)-1;
			del++;
		}
		for(int j = 1; j <= del; j++){
			st.erase(*st.rbegin());
		}
	}
	for(int i = 0;i < n; i++){
		cout<< idx[i] << " ";
	}
	return 0;
}

