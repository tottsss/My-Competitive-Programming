#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int dist(pair<int, int> a, pair<int, int> b){
	int x = a.ff-b.ff, y = a.ss-b.ss;
	return (x*x)+(y*y);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector< pair<int, int> > p(n);
	for(int i = 0;i < n; i++){
		cin >> p[i].ff >> p[i].ss;
	}	
	sort(all(p));
	int best_dist = (int)8e18;
	set<pair<int, int> > st;
	for(int i = 0, j = 0;i < n; i++){
		int h = ceil(sqrt(best_dist));
		while(j < n and p[i].ff - p[j].ff >= h){
			st.erase({p[j].ss, p[j].ff});
			j++;
		}
		auto l = st.lower_bound({p[i].ss-h, p[i].ff});
		auto r = st.upper_bound({p[i].ss+h, p[i].ff});
		for(auto id = l; id != r; id++){
			best_dist = min(best_dist, dist(p[i], make_pair(id->ss, id->ff)));
		}
		st.insert({p[i].ss, p[i].ff});
	}
	
	cout << best_dist;
	return 0;
}

