#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector< pair<int, int> > a(n);
	vector<pair<int, int>> p;
	vector<int> answer(n+1, 0);
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
		p.push_back({a[i].ff, 1});
		p.push_back({a[i].ss+1, -1});
	}
	sort(all(p));
	int ok = 0, last = -1;
	for(auto x : p){
		if(ok != 0){
//			if(answer[ok]==0) answer[ok]++;
			answer[ok]+= x.ff-last;	
		}
		ok+=x.ss;
		last = x.ff;
	}
	for(int i = 1;i <= n; i++) cout << answer[i] << ' ';
	return 0;
}

