#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




int common(pair<int, int> a, pair<int, int> b){
	if(a.ff > b.ss or b.ff > a.ss) return 0;
	int l = max(a.ff, b.ff);
	int r = min(a.ss, b.ss);
	return r-l+1;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int q, t; cin >> q >> t;
	int id = 1, lastans = 0;
	set<int> st;
	map<int, pair<int, int> > mp;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int a, b; cin >> a >> b;
			int l = (a ^ (t * lastans));
			int r = (b ^ (t * lastans));
			if(l > r) swap(l, r);
			mp[id] = {l, r};
			st.insert(id);
			id++;
		}else if(type == 2){
			int idx; cin >> idx;
			if(st.count(idx)==false) assert(false);
			st.erase(idx);
		}else{
			int a, b, k; cin >> a >> b >> k;
			int l = (a ^ (t * lastans));
			int r = (b ^ (t * lastans));
			if(l > r) swap(l, r);
			lastans = 0;
			
			for(int x : st){
				if(common(make_pair(l, r), mp[x]) >= k){
					lastans++;
				}
			}
			cout << lastans << '\n';
		}
	}

	return 0;
}

