#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
vector<int> a, pref;
int up[2*N+1][19], can[2*N];
int n, k;
int get_sum(int l, int r){
	return pref[r] - (!l ? 0LL : pref[l-1]);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0;i < n; i++){
		int x; cin >> x;
		a.push_back(x);
	}
	for(int i = 0;i < n; i++){
		a.push_back(a[i]);
	}
	for(int i = 0;i < a.size(); i++) 
		pref.push_back((pref.empty() ? 0 : pref.back()) + a[i]);
	for(int i = 0;i < a.size(); i++){
		int l = i-1, r = min((int)a.size()-1LL, i + n-1);
		if(get_sum(l, r) <= k){
			up[i][0] = r+1;
		}else{
			while(l + 1 < r){
				int mid = (l + r)>>1;
				if(get_sum(i, mid) > k) r = mid;
				else l = mid;
			}
			up[i][0] = l+1;
		}
	}
	up[a.size()][0] = a.size();
	for(int i = 1;i < 19; i++){
		for(int v = 0; v <= a.size(); v++){
			up[v][i] = up[up[v][i-1]][i-1];
		}
	}
	function<int(int, int)> go_d=[&](int v, int d){
		for(int i = 0;i < 19; i++)
			if(d & (1LL<<i)) v = up[v][i];
		return v;
	};
	int answer = n;
	for(int start = 0; start < n; start++){
		int l = 0, r = n+1;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			if(go_d(start, mid) > start+n-1){
				r = mid;
			}else l = mid;
		}
		answer = min(answer, r);
	}
	cout << answer;
	return 0;
}

