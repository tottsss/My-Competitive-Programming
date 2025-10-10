#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 8e5;
int n, a[N], b[N], c[N];
int q, sz;
struct Q{
	int l, r, x, y, idx;
};
struct upd{
	int x, y, c;
};
vector<upd> updates;
vector<Q> query;
void compress(vector<int>&elem, map<int, int>&mp){
	sz = 1;
	sort(all(elem));
	elem.erase(unique(all(elem)), elem.end());
	for(int x : elem){
		mp[x] = sz++;
	}
}


int tree[4*N];

void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = (x ^ tree[v]);
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos) update(pos, x, v<<1, vl, mid);
		else update(pos, x, v<<1|1, mid+1, vr);
		tree[v] = tree[v<<1] ^ tree[v<<1|1];
	}
}

int get(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr) return tree[v];
	int mid = (vl + vr)>>1;
	return get(l, r, v<<1, vl, mid) ^ get(l, r, v<<1|1, mid+1, vr);
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	vector<int> elem;
	map<int, int> compX, compY;
	for(int i = 0;i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
		elem.push_back(a[i]);
		elem.push_back(b[i]);
	}
	query.resize(q);
	vector<int> ans(q, 0);
	for(int i = 0;i < q; i++){
		cin >> query[i].l >> query[i].r >> query[i].x >> query[i].y;
		query[i].idx = i;
		elem.push_back(query[i].l);
		elem.push_back(query[i].r);
		elem.push_back(query[i].x);
		elem.push_back(query[i].y);
	}
	compress(elem, compY);
	compX = compY;
	for(int i = 0;i < n; i++){
		a[i] = compX[a[i]];
		b[i] = compY[b[i]];
		updates.push_back({a[i], b[i], c[i]});
	}
	int j = 0;
	vector<Q> queries;
	for(int i = 0;i < q; i++){
		query[i].l = compX[query[i].l];
		query[i].r = compX[query[i].r];
		query[i].x = compY[query[i].x];
		query[i].y = compY[query[i].y];
		if(query[i].l != 1){
			queries.push_back({query[i].l - 1, query[i].l - 1, query[i].x, query[i].y, query[i].idx});
		}
		queries.push_back({query[i].r, query[i].r, query[i].x, query[i].y, query[i].idx});
	}
	sort(all(queries), [&](Q A, Q B){
		return A.l<B.l;	
	});
	sort(all(updates), [&](upd A, upd B){
		return A.x < B.x;	
	});

	for(auto [l, r, x, y, idx] : queries){
		while(j < updates.size() and l >= updates[j].x){
			update(updates[j].y, updates[j].c, 1, 1, N);
			j++;
		}
		ans[idx]^= get(x, y, 1, 1, N);
	}
	
	
	for(int i = 0;i < q; i++) cout << ans[i] << '\n';
	return 0;
}

