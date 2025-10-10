#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;


void solve(){
	int n; cin >> n;
	vector< pair<int, pair<int, int>> > a(n), Pref(n);
	vector< pair<int, int> > Lw;
	for(int i =0 ;i < n; i++){
		cin >> a[i].ff >> a[i].ss.ff;
		Lw.push_back({a[i].ff, a[i].ss.ff});
		a[i].ss.ss = i;
	}
	sort(all(a)); sort(all(Lw));
	vector<int> answer(n + 1, -2);
	pair<int, pair<int, int> > pref, cur; cur = a[0];
	Pref[0] = cur;
	for(int i = 1;i < n; i++){
		pref = Pref[i-1];
		cur = a[i];
		if(pref.ss > cur.ss){
			Pref[i] = cur;
		}else if(pref.ff > cur.ff){
			Pref[i] = cur;
		}else{
			Pref[i] = Pref[i-1];
		}
	}
	pair<int,int> cur1;
	for(int i = 0;i < n; i++){
		int idx = a[i].ss.ss;
		cur1 = Lw[i];
		int L = upper_bound(all(Lw), make_pair(cur1.ff-1, cur1.ss)) - Lw.begin();
		while(L >= n) L--;
		while(L >= 0 and Lw[L].ff >= cur1.ff){
			L--;
		}
		if(L < 0 or Pref[L].ss.ff >= cur1.ss) continue;
		int ans = Pref[L].ss.ss;
		answer[idx] = ans;
	}
	for(int i = 0;i < n; i++){
		int idx = a[i].ss.ss;
		if(answer[idx] != -2){
			continue;
		}
		cur1 = {Lw[i].ss, Lw[i].ff};
		int L = upper_bound(all(Lw), make_pair(cur1.ff-1, cur1.ss)) - Lw.begin();
		while(L >= n) L--;
		while(L >= 0 and Lw[L].ff >= cur1.ff){
			L--;
		}
		if(L < 0 or Pref[L].ss.ff >= cur1.ss) continue;
		int ans = Pref[L].ss.ss;
		answer[idx] = ans;
	}
	for(int i = 0;i < n; i++) cout << answer[i] + 1 << ' ';
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
