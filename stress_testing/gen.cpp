#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<int>(l, r)(rng)

signed main(){
	int n = rnd(5, 10);
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		a[i] = rnd(1, 50);
	}
	cout << n << '\n';
	for(int i = 0;i < n; i++) cout << a[i] << ' ';
	return 0;
}

