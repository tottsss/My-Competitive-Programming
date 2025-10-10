#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

multiset<pair<int, int>>  T[1<<19];
int n, q, a[(1<<19)];
vector<int> Dee;

void update(int pos, int x, int v, int vl, int vr){
	T[v].erase({a[pos], pos});
	T[v].insert({x, pos});
	if(vl == vr){
		a[pos] = x;
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos)
			update(pos, x, v<<1|1, vl, mid);
		else 
			update(pos, x, (v<<1) + 2, mid+1, vr);
	}
}

void Delete(int pos, int v, int vl, int vr){
	T[v].erase({a[pos], pos});
	if(vl == vr){
		
	}else{
		int mid =(vl + vr)>>1;
		if(mid>= pos) Delete(pos, v<<1|1, vl, mid);
		else Delete(pos, (v<<1) + 2, mid+1,vr);
	}
}

int query(int l, int r, int x,  int v, int vl, int vr){
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr){
		if(T[v].empty()) return 0;
		int sz = 0;
		auto it = T[v].begin();
		while(it != T[v].end() and it->first <= x){
			Dee.push_back(it->second);
			sz++, it++;
		}
		return sz;
	}
	int mid = (vl + vr)>>1;
	int A = query(l, r, x,  v<<1|1, vl, mid);
	int B = query(l, r, x , (v<<1) + 2, mid+1, vr);
	return A+B;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int pos, x; 
			cin >> pos >> x;
			update(pos, x, 0, 0, n);
		}else{
			int l, r, x;
			cin >> l >> r >> x;
			cout << query(l, r-1, x, 0, 0, n) << '\n';
			for(auto to : Dee){
				Delete(to, 0, 0, n);
			}
			
			Dee.clear();
		}
	}
	return 0;
}

