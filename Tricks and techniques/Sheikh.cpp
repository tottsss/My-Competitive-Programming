#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


void solve(){
	int n, q; cin >> n >> q;
	vector<int> a(n + 1,0), s(n + 1,0), x(n + 1,0);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		x[i] = (x[i-1]^a[i]);
	}
	
	function<int(int, int)> get_f=[&](int l, int r){
		return (s[r]-s[l-1])-(x[r]^x[l-1]);
	};
	
	while(q--){
		int L, R; cin >> L>>R;
		int ansl = L, ansr = R, l = L, r = R;
		int ans = get_f(L,R);
		if(ans == 0){
			cout << R << ' ' << R << '\n';
			continue;
		}
		while((x[r]^x[l-1]) == (x[r]^x[l]) + a[l]) l++;
		while( (x[r]^x[l-1]) == (x[r-1]^x[l-1]) + a[r]) r--;
		ansl = l, ansr = r;
		l--;
		while(l >= L){
			while((x[r]^x[l-1]) == (x[r-1]^x[l-1]) + a[r]) r--;
			if(r-l<ansr-ansl){
				ansl = l,ansr=r;
			}
			l--;
		}
//		if(get_f(ansl, ansr) != get_f(L,R)) assert(false);
		cout << ansl << " " << ansr << '\n';
	}
	
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

