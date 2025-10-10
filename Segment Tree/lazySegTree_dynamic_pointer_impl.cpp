#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9;

int n;
struct node{
	node* left = nullptr;
	node* right = nullptr;
	int sum = 0, lazy = 0;	
};
typedef node* pnode;


void push(pnode &tree, int v, int vl, int vr){
	if(tree==nullptr) tree = new node();
	if(tree->lazy == 0) return;
	tree->sum+= (vr-vl+1)*tree->lazy;
	if(vl != vr){
		if(tree->left == nullptr) tree->left = new node();
		if(tree->right == nullptr) tree->right = new node(); 
		tree->left->lazy+= tree->lazy;
		tree->right->lazy+= tree->lazy;
	}
	tree->lazy = 0;
}

int sum(pnode t){
	return (t ? t->sum : 0LL);
}

void update(pnode &tree, int pos, int x, int v = 1, int vl =0 , int vr = n){
	if(tree==nullptr) tree = new node();
	if(vl == vr){
		tree->sum = x;
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos){
			update(tree->left, pos, x, v<<1, vl, mid);
		}else{
			update(tree->right, pos, x, v<<1|1, mid+1, vr);
		}
		tree->sum = sum(tree->left) + sum(tree->right);
	}
}



int get_sum(pnode &tree, int l, int r, int v = 1, int vl = 0, int vr = n){
	if(tree == nullptr) tree = new node();
	push(tree, v, vl, vr);
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return tree->sum;
	}
	int mid = (vl + vr)>>1;
	int s = (tree->left ? get_sum(tree->left, l, r, v<<1, vl, mid) : 0);
	int s1 = (tree->right ? get_sum(tree->right, l, r, v<<1|1, mid+1, vr) : 0);
	return s+s1;
}

void add(pnode&tree, int l, int r, int x, int v = 1, int vl = 0, int vr = n){
	if(tree == nullptr) tree = new node();
	push(tree, v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		tree->lazy+= x;
		push(tree, v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(tree->left, l, r, x, v<<1, vl, mid);
	add(tree->right, l, r, x, v<<1|1, mid+1, vr);
	tree->sum = sum(tree->left) + sum(tree->right);
}


main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);
	pnode tree = new node();
	n = M-1;
	int q; cin >> q; 
	int Q; cin >> Q;
	while(q--){
		int l, r, x; cin >> l >> r >> x;
		add(tree, l, r-1, x);
	}
	while(Q--){
		int l, r; cin >> l >> r;
		cout << get_sum(tree, l,r-1) << '\n';
	}
	return 0;
}

