#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}


signed main () {
	int n; cin >> n;
	vector< pair<int, int> > a(n);
	vector< pair<int, int> > b(n);
	vector<int> sum, dif;
	int mx = 0;
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
		sum.push_back(a[i].ff+a[i].ss);
		dif.push_back(a[i].ff-a[i].ss);
		b[i] = a[i];
	}
	sort(all(a), [&](pair<int, int> A, pair<int, int> B){
		if(A.ff == B.ff){
			return A.ss<B.ss;
		}	
		return A.ff<B.ff;
	});
	sort(all(b), [&](pair<int, int> A, pair<int, int> B){
		if(A.ss == B.ss){
			return A.ff<B.ff;
		}	
		return A.ss<B.ss;
	});
	for(int i = 0;i < n; i++){
		mx = max(mx, dist(a[0], a[i]));
	}
	for(int i = 0;i < n; i++){
		mx = max(mx, dist(a[n-1], a[i]));
	}
	for(int i = 0;i < n; i++){
		mx = max(mx, dist(b[0], b[i]));
	}
	for(int i = 0;i < n; i++){
		mx = max(mx, dist(b[n-1], b[i]));
	}
	sort(all(dif));
	sort(all(sum));
	mx = max(mx, sum.back()-sum[0]);
	mx = max(mx, dif.back()-dif[0]);
	cout << mx;
	return 0;
}