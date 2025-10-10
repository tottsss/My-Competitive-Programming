#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


vector<pair<int, int> > ans;
vector<pair<int, int> > cont;
void f(vector< pair<int, int> > &a){
	// sorted by right-side
	cont.clear();
	for(pair<int,int> x : a){
		if(cont.empty() or x.ff > cont.back().ss){
			cont.push_back(x);
		}
	}
	if(cont.size() > ans.size()){
		ans = cont;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	map<int, vector<pair<int, int>> > mp;
	for(int r = 0; r < n; r++){
		int sum = 0;
		for(int l = r; l >= 0; l--){
			sum+= a[l];
			mp[sum].push_back({l, r});
		}
	}
	for(auto x : mp){
		if(ans.size() > x.ss.size()) continue;
		f(x.ss);
	}
	cout << ans.size() << '\n';
	for(pair<int, int> x : ans){
		cout << x.ff+1 << ' ' << x.ss+1 << '\n';
	}
	return 0;
}

