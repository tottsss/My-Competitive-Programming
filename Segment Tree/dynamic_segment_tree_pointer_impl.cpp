#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9+7;

int n, m;
int P = 91, Q = 47;

struct node{
	node* left = nullptr;
	node* right = nullptr;
	int sum = 0;	
};

typedef node* pnode;

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
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return tree->sum;
	}
	int mid = (vl + vr)>>1;
	int s = (tree->left ? get_sum(tree->left, l, r, v<<1, vl, mid) : 0);
	int s1 = (tree->right ? get_sum(tree->right, l, r, v<<1|1, mid+1, vr) : 0);
	return s+s1;
}
// https://www.eolymp.com/ru/problems/3252
main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);
	pnode tree = new node();
	cin >> n >> m;
	while(m--){
		char type; cin >> type;
		int A,B; cin >> A >> B;
		if(type == '!'){
			int pos = (A+P)%n;
			int x = (B+Q)%M;
//			cout << pos << '\n';
			update(tree, pos, x);
		}else{
			int l = (A+P)%n;
			int r = (B+Q)%n;
			if(l > r) swap(l, r);
			int Z = get_sum(tree, l, r);
			P = ((P*31)+Z )%M;
			Q = ((Q*29)+Z)%M;
			cout << Z << '\n';
		}
		
	}

	return 0;
}

