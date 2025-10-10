#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e7+19;




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n), used(n+2,0);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		if(i < k) used[a[i]] = 1;
	}

	int mx = -1000, idx = 0, mex = 1;
	for(int i = k;i <= n; i++){
		while(used[mex]){
			mex++;
		}
		if(mex-1 > mx){
			mx = mex-1;
			idx = i-k+1;
		}
		if(i == n) break;
		if(mex >= a[i-k]){
			mex = a[i-k];
		}
		used[a[i]] = 1, used[a[i-k]] =0;
	}
	cout << mx << ' ' << idx;
	return 0;
}

