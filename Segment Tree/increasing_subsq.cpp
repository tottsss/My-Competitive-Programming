#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
const int mod = 1e9 + 7;

int tree[4*N+10];
map<int, int> compress;
int n, a[N+10], sz = 1;

void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v] = (tree[v] + x) % mod;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1] + tree[v<<1|1];
}

int sum(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return tree[v]%mod;
	}
	int mid = (vl + vr)>>1;
	return (sum(l, r, v<<1, vl, mid) + sum(l, r, v<<1|1, mid+1, vr))%mod;
}
// https://cses.fi/problemset/task/1748
/*

Given an array of n integers, your task is 
to calculate the number of increasing subsequences it contains.
 If two subsequences have the same values but in different positions in the array, they are counted separately.
Print one integer: the number of increasing subsequences modulo 109+7.
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> c;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		c.push_back(a[i]);
	}
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	for(int x : c){
		compress[x] = sz++;
	}
	sz--;
	for(int i = 1;i <= n; i++){
		update(compress[a[i]], 1 + (compress[a[i]] > 1 ? sum(1, compress[a[i]] - 1, 1, 1, sz) : 0), 1, 1, sz);
	}
	cout << sum(1, sz, 1, 1, sz);
	return 0;
}

