#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second	
const int N = 1e5 + 1;
int a[N];
pair<int, int> tree[4 * N];
int n, q;
pair<int, int> combine(pair<int, int> A, pair<int, int> b){
	if(A.ff == b.ff) return {A.ff, A.ss+b.ss};
	if(A.ff > b.ff) return b;
	return A; 
}
void update(int i, int v){
	i = i + n, tree[i] = {v,1}, i/= 2;
	while(i > 0){
		tree[i] = combine(tree[i * 2 + 1], tree[i * 2]);
		i/= 2;
	}
}
pair<int,int> query(int l, int r){
	pair<int, int> S = {INT_MAX, 0};
	 l += n, r+= n;
	while(r >= l){
		if(l % 2 == 1) S= combine(S, tree[l]), l++;
		if(r % 2 == 0) S= combine(S, tree[r]), r--;
		l/= 2;
		r/= 2;
	}
	return S;
}



void build(){
	for(int i = 0;i < n; i++){
		tree[i + n] = {a[i], 1};
	}
	for(int i = n - 1;i >= 0; i--){
		tree[i] = combine(tree[i * 2],  tree[i * 2 + 1]);
	}
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	build();
	while(q--){
		int c, l, r;
		cin >> c >> l >> r;
		if(c == 1){
			update(l, r);
		}else{
			pair<int, int> s = query(l, r-1);
			cout << s.ff << ' ' << s.ss << '\n';
//			cout << query(l, r - 1) << '\n';
		}
	}
	return 0;
}
