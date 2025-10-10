#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;
int a[N], tree[4 * N];
int n, q;
void update(int i, int v){
	i = i + n, tree[i] = v, i/= 2;
	while(i > 0){
		tree[i] = tree[i * 2 + 1] + tree[i * 2];
		i/= 2;
	}
}
int sum(int l, int r){
	int S = 0; l += n, r+= n;
	while(r >= l){
		if(l % 2 == 1) S+= tree[l], l++;
		if(r % 2 == 0) S+= tree[r], r--;
		l/= 2;
		r/= 2;
	}
	return S;
}
void build(){
	for(int i = 0;i < n; i++){
		tree[i + n] = a[i];
	}
	for(int i = n - 1;i >= 0; i--){
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
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
			cout << sum(l, r - 1) << '\n';
		}
	}
	return 0;
}
