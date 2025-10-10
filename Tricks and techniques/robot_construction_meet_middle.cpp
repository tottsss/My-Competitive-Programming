#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const long long M = 1e9 + 7;
int Left[21][(1<<20) + 10];
unordered_map<long long, int> mp;
int T;

long long f(long long x, long long y){
	return x * M + y;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int> > a(n);
	int X, Y; cin >> X >> Y;
	vector<int> ans(n + 1, 0);
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
	}
	int mid = n / 2;
	for(int mask = 0;mask < (1<<mid); mask++){
		int cnt = 0, x = 0, y = 0;
		for(int i = 0;i < n; i++){
			if(mask & (1<<i)){
				cnt++;
				x+= a[i].ff, y+= a[i].ss;
			}
		}
		if(mp.count(f(x, y)) == false) mp[f(x, y)] = ++T;
		Left[cnt][mp[f(x, y)]]++;
	}
	for(int mask = 0; mask < (1<<(n-mid)); mask++){
		int cntR = 0, x = 0, y = 0;
		for(int i = 0;i < (n - mid); i++){
			if(mask & (1<<i)){
				cntR++;
				x+= a[mid + i].ff, y+= a[mid + i].ss;
			}
		}
		if(mp.count(f(X-x, Y-y)) == false) continue;
		int c = mp[f(X-x, Y-y)];
		for(int cntL = 0;cntL <= mid; cntL++){
			ans[cntR + cntL]+= Left[cntL][c];
		}
	}
	for(int i = 1;i <= n; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}

