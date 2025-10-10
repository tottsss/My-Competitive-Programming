#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 4e5;
int n, q;
pair<int, int> query[N + 10];
pair<pair<int, int>, int> updates[N + 10];
int width[N + 10], value[N + 10], pref[N + 10], diff[N + 10];
vector<int> indices;


int get(int idx){
	return (lower_bound(all(indices), idx) - indices.begin());
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 0;i < n; i++){
		int l, r, x; cin >> l >> r >> x;
		indices.push_back(l);
		indices.push_back(r);
		updates[i] = {{l, r}, x};
	}
	for(int i = 0;i < q; i++){
		int l, r; cin >> l >> r;
		indices.push_back(l);
		indices.push_back(r);
		query[i] = {l,r};
	}
	sort(all(indices));
	indices.erase(unique(all(indices)), indices.end());
	for(int i = 0;i < n; i++){
		int l = updates[i].ff.ff;
		int r = updates[i].ff.ss;
		int x = updates[i].ss;
		diff[get(l)+1]+= x;
		diff[get(r)+1]-= x;
	}
//	for(auto x : indices) cout << x << ' ';
//	cout << '\n';
	for(int i = 1;i < indices.size(); i++){
		width[i] = indices[i] - indices[i-1];
	}
	for(int i = 1;i < indices.size(); i++){
		value[i] = value[i-1] + diff[i];
	}
	for(int i = 1;i < indices.size(); i++){
		pref[i] = pref[i-1] + width[i]*value[i];
	}
	for(int i = 0;i < q; i++){
		int l = query[i].ff;
		int r = query[i].ss;
		cout << pref[get(r)]-pref[get(l)] << '\n';
	}
	return 0;
}

