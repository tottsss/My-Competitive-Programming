#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e6;
int tree[4*N];

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 1;
		return;
	}
	int mid = (vl+vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1]+tree[v<<1|1];
}

int get_k(int k, int v, int vl, int vr){
	if(vl == vr) return vl;
	int mid = (vl + vr)>>1;
	if(tree[v<<1] >= k){
		return get_k(k, v<<1, vl, mid);
	}else{
		return get_k(k-tree[v<<1], v<<1|1, mid+1, vr);
	}
}

void update(int pos, int v, int vl, int vr){
	if(vl == vr){
		tree[v]^= 1;
		return;
	}
	int mid = (vl+vr)>>1;
	if(mid>=pos) update(pos, v<<1, vl, mid);
	else update(pos, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1]+tree[v<<1|1];
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	ifstream cin("joseph.in");
	ofstream cout("joseph.out");
	// https://codeforces.com/group/ilq9y7l62y/contest/100135/attachments
	// problem K
	int n; cin >> n;
	int p; cin >> p;
	build(1, 1, n);
	int last = 0;
	while(tree[1] > 1){
		int k = (last + p)%tree[1];
		if(k==0) k = tree[1];
		last = k-1;
		int pos = get_k(k, 1, 1, n);
		update(pos, 1, 1, n);
	}
	cout << get_k(1, 1, 1, n);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 1e6;
int tree[4*N];

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 1;
		return;
	}
	int mid = (vl+vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1]+tree[v<<1|1];
}

int get_k(int k, int v, int vl, int vr){
	if(vl == vr) return vl;
	int mid = (vl + vr)>>1;
	if(tree[v<<1] >= k){
		return get_k(k, v<<1, vl, mid);
	}else{
		return get_k(k-tree[v<<1], v<<1|1, mid+1, vr);
	}
}

void update(int pos, int v, int vl, int vr){
	if(vl == vr){
		tree[v]^= 1;
		return;
	}
	int mid = (vl+vr)>>1;
	if(mid>=pos) update(pos, v<<1, vl, mid);
	else update(pos, v<<1|1, mid+1, vr);
	tree[v] = tree[v<<1]+tree[v<<1|1];
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	ifstream cin("joseph.in");
	ofstream cout("joseph.out");
	// https://codeforces.com/group/ilq9y7l62y/contest/100135/attachments
	// problem K
	int n; cin >> n;
	int p; cin >> p;
	build(1, 1, n);
	int last = 0;
	while(tree[1] > 1){
		int k = (last + p)%tree[1];
		if(k==0) k = tree[1];
		last = k-1;
		int pos = get_k(k, 1, 1, n);
		update(pos, 1, 1, n);
	}
	cout << get_k(1, 1, 1, n);
	return 0;
}