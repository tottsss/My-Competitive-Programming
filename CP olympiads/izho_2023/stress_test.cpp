#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5 + 1;

int sum(int x){
	int s = 0;
	while(x > 0){
		s+= (x%10);
		x/= 10;
	}
	return s;
}

void solve(){
	int n, q; cin >> n >> q;
	vector<int> tree(4 * n, 0), lazy(4*n, 0);
	vector<int> a(n);
	map<int, vector<int> > mp;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		int x = a[i];
		while(true){
			mp[i].push_back(x);
			if(x < 10) break;
			x = sum(x);
		}
	}
	function<void(int, int, int)> push=[&](int v, int vl, int vr){
		if(lazy[v] == 0) return;
		tree[v]+= ((vr-vl+1) * lazy[v]);
		if(vl != vr){
			lazy[v<<1|1] +=lazy[v];
			lazy[(v<<1) + 2]+= lazy[v]; 
		}	
		lazy[v] = 0;
	};
	function<void(int,int, int, int, int)> update=[&](int l, int r, int v, int vl, int vr){
		push(v, vl, vr);
		if(l > vr or vl > r) return;
		if(l <= vl and r >= vr){
			lazy[v]++;
			push(v, vl, vr);
			return;
		}	
		int mid = (vl + vr)>>1;
		update(l, r, v<<1|1, vl, mid);
		update(l, r, v*2+2, mid+1, vr);
	};
	function<int(int, int, int, int)> get=[&](int pos, int v, int vl, int vr){
		push(v, vl, vr);
		if(vl == vr){
			return tree[v];
		}
		int mid = (vl + vr)>>1;
		if(mid >= pos) return get(pos, v<<1|1, vl, mid);
		else return get(pos, v*2+2, mid+1, vr);
	};
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			l--, r--;
			update(l, r, 0, 0, n);
		}else{
			int pos; cin >> pos; pos--;
			cout << mp[pos][min(get(pos, 0, 0, n), (int)mp[pos].size()-1)] << '\n';
		}
	}	
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
//		cout << '\n';
	}
	return 0;
}
