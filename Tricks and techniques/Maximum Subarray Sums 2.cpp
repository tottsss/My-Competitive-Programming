#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e18;
signed main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector <int> v(n+1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = 1; i <= n; i++)
		v[i] += v[i-1];
	set <pair<int, int>> r;
	for(int i = a; i<= b; i++)
		r.insert({v[i], i});
	int mxs = -INF;
	for(int i = 1; i <= n-a+1; i++){
		mxs = max(mxs, r.rbegin()->first-v[i-1]);
		r.erase({v[i+a-1], i+a-1});
		if(i + b <= n)
			r.insert({v[i+b], i+b}); 
	}
	cout << mxs;
}