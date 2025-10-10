#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int> > job(k);
	for(int i = 0;i < k; i++){
		cin >> job[i].ff;
		job[i].ss = i;
	}
	sort(all(job));
	function<int(int, int)> good=[&](int machine, int pr){
		int j = 0;
		for(int i = 1;i <= n; i++){
			int cnt = 0;
			while(cnt < machine && j < k){
				if(i < job[j].ff) break;
				if(i > job[j].ff + m) return 0;
				if(pr) cout << job[j].ss+1 << ' ';
				j++, cnt++;
			}
			if(pr) cout << 0 << '\n';	
		}
		if(j < k) return 0;
		return 1;
	};
	/*
	8 2 12
	1 2 4 2 1 3 5 6 2 3 6 4
	*/
	int l = 0, r = (int)2e6;
	while(l + 1 < r){
		int mid = (l + r)>>1;
		if(good(mid, 0)){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout << r << '\n';
	if(!good(r, 0)) assert(false);
	good(r, 1);
	return 0;
}

