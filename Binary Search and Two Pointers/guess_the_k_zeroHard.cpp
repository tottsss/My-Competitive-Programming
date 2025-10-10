#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int ask(int l, int r){
	cout << "? " << l << ' ' << r << endl;
	int x; cin >> x;
	return x;
}

int asked(int l, int r){
	if(mp.count({l, r})) return mp[{l, r}];
	int sum = ask(l, r);
	mp[{l, r}] = sum;
	return sum;
} 

void update(int pos, int l, int r){
	if(mp.count({l, r})) mp[{l, r}]++;
	if(l != r){
		int mid = (l + r) >>1;
		if(mid >= pos){
			update(pos, l, mid);
		}else update(pos, mid+1, r);
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, t; cin >> n >> t;
	while(t--){
		int k, l = 1, r = n; cin >> k;
		int Z = k;
		for(int round = 1; round <= 20; round++){
			if(l > r) break;
			int mid = (l + r)>>1;
			int zero = asked(l, mid);
			zero = (mid-l+1) - zero;
			if(zero >= k){
				r = mid-1;
			}else{
				
				k-= zero;
				l = mid + 1;
			}
		}
		int answer = l; k =Z;
		cout << "! " << answer << endl;
		 l = 1, r = n;
		for(int round = 1; round <= 20; round++){
			if(l > r) break;
			int mid = (l + r)>>1;
			int zero = asked(l, mid);
			if(l <= answer and answer <= mid){
				mp[{l, mid}]++;
			}
			zero = (mid-l+1) - zero;
			if(zero >= k){
				r = mid-1;
			}else{
				k-= zero;
				l = mid + 1;
			}
		}
	}
	
	return 0;
}

