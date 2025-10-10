#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;

struct P{
	int T, l, r, z;
};
int is_overlap(pair<int, int> a, pair<int, int> b){
	if(b.ff > a.ss or a.ff > b.ss) return 0;
	return 1;
}
pair<int, int> lish;
void overlap(pair<int, int> &a, pair<int, int> &b, int z, int z1){
	if(b.ff <= a.ff and b.ss >= a.ss){
		a = {-1, -1};
		return;
	}
	if(!is_overlap(a,b)) return;
	if(z == z1 and z == 1){
		b = {min(max(1, a.ff), b.ff), max(a.ss, b.ss)};
		a = {-1, -1};
		return;
	}
	if(a.ff <= b.ff and a.ss >= b.ss){
		lish = {a.ff, b.ff-1};
		a = {b.ss+1, a.ss};
		return;
	}
	if(b.ss <= a.ss){
		a = {b.ss+1, a.ss};
	}else{
		a = {a.ff, b.ff-1};
	}
}
int len(pair<int, int> a){
	if(min(a.ff, a.ss) < 0) return 0;
	if(a.ff > a.ss) return 0;
	return a.ss-a.ff+1;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, vector<P> >paint;
	for(int i = 0;i < n; i++){
		int a, b, c, d, z; cin >> a >> b >> c >> d >> z;
		if(b > d) swap(b,d);
		for(int row = min(a, c); row <= max(a, c); row++){
			paint[row].push_back({i, b, d, z});
		}
	}
	// KRSU 1042
	int ans = 0;
	vector<pair<int, int> > del;
	multiset<pair<int, int> > one;
	for(int row = 1; row <= N; row++){
		sort(all(paint[row]), [&](P A, P B){
			return A.T < B.T;	
		});
		for(P x : paint[row]){
			pair<int, int> cur = {x.l, x.r};
			int z = x.z;
			for(pair<int, int> o : one){
				pair<int, int> cur1=o;
				lish = {-1, -1};
				overlap(cur1, cur, 1, z);
				if(len(cur1) > 0) del.push_back(cur1);
				if(len(lish) > 0) del.push_back(lish);
			}
			one.clear();
			if(z==1) del.push_back(cur);
			for(pair<int, int> D : del){
				one.insert(D);
			}
			del.clear();
		}
		for(pair<int, int> o : one){
			ans = (ans + len(o))%2019;
		}
		one.clear();
	}
	cout << ans;
	return 0;
}

