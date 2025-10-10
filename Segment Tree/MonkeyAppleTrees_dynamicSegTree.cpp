#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1000000000;
int C, Q;
struct node{
	node *left=nullptr, *right=nullptr;
	int sum = 0, lazy = 0;	
};
typedef node* pnode;
void push(pnode &tree, int vl, int vr){
	if(!tree) tree = new node();
	if(tree->lazy == 0) return;
	tree->sum = (vr-vl+1);
	if(vl != vr){
		if(!tree->left) tree->left = new node();
		if(!tree->right) tree->right = new node();
		tree->left->lazy = 1;
		tree->right->lazy = 1;
	}
	tree->lazy = 0;	
}
int sum(pnode tree){
	if(tree) return tree->sum;
	return 0;
}
void update(pnode &tree, int l, int r, int vl, int vr){
	if(!tree) tree = new node();
	push(tree, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		tree->lazy = 1;
		push(tree, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(tree->left, l, r, vl, mid);
	update(tree->right, l, r, mid+1, vr);
	tree->sum = sum(tree->left) + sum(tree->right);
}

int get_sum(pnode &tree, int l, int r, int vl, int vr){
	if(!tree){
		tree = new node();
	}
	push(tree, vl, vr);
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr){
		return tree->sum;
	}
	int mid = (vl + vr)>>1;
	int s = (tree->left ? get_sum(tree->left,l, r, vl, mid) : 0);
	int s1 = (tree->right ? get_sum(tree->right, l, r, mid+1, vr) : 0);
	tree->sum = sum(tree->left) + sum(tree->right);
	return s+s1;
}
// https://oj.uz/problem/view/IZhO12_apple

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	pnode tree = new node();
	cin >> Q;
	while(Q--){
		int type, l, r; cin >> type >> l >> r;
		if(type == 1){
			C = get_sum(tree, l+C, r+C, 1, N);
			cout << C << '\n';
		}else{
			update(tree, l+C, r+C, 1, N);
		}
	}
	return 0;
}

