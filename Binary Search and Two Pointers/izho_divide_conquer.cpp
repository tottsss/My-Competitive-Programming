#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
//   ifstream cin("divide.in");
//   ofstream cout("divide.out");
	int n; cin >> n;
	int x[n], g[n], d[n];
	for(int i = 0;i < n; i++){
		cin >> x[i] >> g[i] >> d[i];
	}
	int gold[n], energy[n], Min[n]; gold[0] = g[0], energy[0] = d[0], Min[0] = -x[0];
	for(int i = 1;i < n; i++){
		gold[i] = gold[i-1] + g[i];
		energy[i] = energy[i-1]+d[i];
		Min[i] = min(Min[i-1], energy[i-1]-x[i]);
	}
	int answer = 0;
	function<int(int, int)> check=[&](int i, int j){
		if(i > j) swap(i, j);
		int s_g = gold[j] - (i > 0 ? gold[i-1] : 0);
		int s_e = energy[j] - (i > 0 ? energy[i-1] : 0);
		if(s_e >= x[j]-x[i]){
			answer = max(answer, s_g);
			return 1;
		}
		// energy[j] - energy[i-1] >= x[j] - x[i]  = true
		// energy[j] >= x[j]-x[i] + energy[i-1] = true;
		// energy[j] - x[j] >= -x[i]+energy[i-1]
		// energy[j] - x[j] >= energy[i-1]-x[i];
		// energy[j]-x[j] + x[i] >= energy[i-1]
		return 0;
	};
	for(int j = n-1; j >= 0; j--){
		answer = max(answer, g[j]);
		int l = 0, r = j, cnt = 0;
		if(check(0,j)) continue;
		while(l + 1 < r){
			if(cnt > 30) break;
			cnt++;
			int mid = (l + r)>>1;
			if(energy[j]-x[j] >= Min[mid]){
				check(j, mid);
				r = mid;
			}else l = mid;
		}
	}
	cout << answer;
	return 0;
}

