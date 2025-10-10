#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

pair<int, int> tree[(1<<20)];
int lazy[(1<<20)];
pair<int, int> combine(pair<int, int> a, pair<int, int> b){
	if(a.ff == b.ff){
		if(a.ss > b.ss) return b;
		 return a;
	}else if(a.ff > b.ff) return a;
	 return b;
}

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = {0, vl};
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1|1, vl, mid);
	 build((v << 1) + 2, mid +1, vr);
	tree[v] = combine(tree[v<<1|1], tree[(v << 1) + 2]);
}

void push(int v, int vl, int vr){
	tree[v].ff+= lazy[v];
	if(vl != vr){
		lazy[v<<1|1]+= lazy[v];
		lazy[(v << 1) + 2]+= lazy[v];
	}
	lazy[v] = 0;
}


void add(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(vl > r or l > vr) return;
	if(l <= vl and r >= vr){
		lazy[v]+= x;
		push(v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(l, r, x, v<<1|1, vl, mid);
	add(l, r, x, (v << 1) + 2, mid+1, vr);	
	tree[v] = combine(tree[v<<1 | 1], tree[(v << 1) + 2]);
}

int Bigger(int l , int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(tree[v].ff < x) return -1;
	if(l > vr) return -1;
	if(vl == vr){
		return vl;
	}
	int mid = (vl + vr)>>1;
	int answer = Bigger(l, x, v<<1 | 1, vl, mid);
	if(answer == -1) answer = Bigger(l, x, (v << 1) + 2, mid+1, vr);
//	tree[v] = combine(tree[v<<1 | 1], tree[v<<1 + 2]);
	return answer;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	build(0, 0, n);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r, x; cin >> l >> r >> x;
			add(l, r-1, x, 0, 0, n);
		}else{
			int x, l; cin >> x >> l;
			cout << Bigger(l, x, 0, 0, n) << '\n';
		}
		push(0, 0, n);
//		cout << tree[0].ff << endl;
	}
	return 0;
}

