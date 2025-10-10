#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 3e5;
int tree[N*4];
vector<pair<int, int> >query[N*2];
vector<pair<int, int> > updates[2*N];
int n, q, m;
void add(int pos,int x, int v,  int vl, int vr){
	if(vl == vr){
		tree[v]+= x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) add(pos, x, v<<1, vl, mid);
	else add(pos, x, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1]+tree[v<<1|1];
}
int sum(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	return sum(l, r, v<<1, vl, mid)+sum(l, r, v<<1|1, mid+1, vr);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q >> m;
	for(int i = 0;i < q; i++){
		int l, r, x; cin >> l >> r >> x;
		updates[l].push_back({x, i});
		if(r < n) updates[r+1].push_back({-x, i});
	}
	vector<int> answer(m, -2);
	for(int i = 0;i < m; i++){
		int pos, x; cin >> pos >> x;
		query[pos].push_back({x, i});
	}
	for(int i = 1;i <= n; i++){
		for(auto Q : updates[i]){
			add(Q.ss, Q.ff, 1, 0, q);
		}
		for(auto Q : query[i]){
			if(sum(0, 0, 1, 0, q) >= Q.ff){
				answer[Q.ss] = 0;
				continue;
			}
			if(sum(0, q-1, 1, 0, q) < Q.ff){
				continue;
			}
			int l = 0, r = q;
			while(l+1 < r){
				int mid = (l + r)>>1;
				if(sum(0, mid, 1, 0, q) >= Q.ff){
					r = mid;
				}else l = mid;
			}
			answer[Q.ss] = r;
		}
	}
	for(int i = 0;i < m; i++){
		cout << 1+answer[i] << '\n';
	}
	return 0;
}

