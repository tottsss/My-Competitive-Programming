#include <bits/stdc++.h>
using namespace std;
#define int  long long
struct node {
	long long prior, cnt, rev, mn;
	long long  sum;
	int key;
	node * l, * r;
	node() {}
	node(long long key) : key(key), mn(0LL), rev(0LL), sum(key), prior(rand()), cnt(1LL), l(nullptr), r(nullptr) {}
};                                         
typedef node * pnode;
 
int cnt(pnode t) {	
	return (t ? t->cnt : 0LL);
}
long long sum(pnode t) {
	return (t ? t->sum : 0LL);
}
int Min(pnode t){
	if(!t) return INT_MAX;
	return t->mn;
}
void upd(pnode t) {
	if (t) {
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
		t->sum = t->key + sum(t->l) + sum(t->r) * 1LL;
		t->mn = min({t->key, Min(t->l), Min(t->r)});
	}
}
void push(pnode t){
	if(t and t->rev == 1){
		swap(t->l, t->r);
		if(t->l) t->l->rev^= 1;
		if(t->r) t->r->rev^= 1;
		t->rev = 0LL;
	}
}
  
void merge(pnode & t, pnode l, pnode r) {
	push(l), push(r);
	if(l == NULL) t = r;
	else if(r == NULL) t=l;
	else if (l->prior > r->prior){
		merge(l->r, l->r, r);
		t = l;
	}else{
		merge(r->l, l, r->l);
		 t = r;
	}
	upd(t);
}
 
void split(pnode t, pnode & l, pnode & r, int len) {
	push(t);
	if (!t){
		l= NULL, r = NULL;
		return;
	}else if (len <= cnt(t->l))
		split(t->l, l, t->l, len), r = t;
	else
		split(t->r, t->r, r, len - cnt(t->l) - 1), l = t;
	upd(l), upd(r), upd(t);
}
 
 
int k_th(pnode t, int k){
	if(!t) return -1;
	else if(cnt(t->l) + 1 == k){
		return t->key;
	}else if(cnt(t->l) >= k) return k_th(t->l, k);
	else return k_th(t->r, k-cnt(t->l)-1);
} 
 
void print(pnode t) {
	push(t);
	if (!t) return;
	print(t->l);
	cout << t->key;
	print(t->r);   
}
 
long long get_sum(pnode & t, int x, int y) {
	// get the sum in range [x, y]
	upd(t);
	push(t);
	upd(t);
	pnode l, r;
	split(t, t, l, x-1);
	split(l, l, r, y - x + 1);
	upd(l), upd(r), upd(t);
	int ans = sum(l) * 1LL;
	merge(l, l, r);
	merge(t, t, l);
	return ans * 1LL;
}
long long get_min(pnode & t, int x, int y) {
	// get the min in range [x, y]
	push(t);
	pnode l, r;
	split(t, t, l, x-1);
	split(l, l, r, y - x + 1);
	long long  ans = Min(l);
	merge(l, l, r);
	merge(t, t, l);
	return ans;
}
 
  void delete_i(pnode &t, int x){
 	upd(t);
 	pnode l = nullptr;
 	split(t, l, t, x-1);
 	pnode ans = nullptr;
 	split(t, ans, t, 1);
 	merge(t, l, t);
 }
 
void push_after_i(pnode &t, int pos, int x){
	upd(t);
	pnode l = nullptr;
	split(t, l, t, pos-1);
	pnode ans = nullptr;
	split(t, ans, t, 1);
	upd(ans), upd(l), upd(t);
	merge(ans, new node(x), ans);
	upd(ans), upd(l), upd(t);
	merge(l, l, ans);
	merge(t, l, t);
	
}
void update_pos(pnode &t,int val,  int x, int y){
	// update at pos [x] to val;
	upd(t);
	push(t);
	 upd(t);
	pnode l, r;
	split(t, t, l, x-1);
	split(l, l, r, y-x+1);
	l->key = val;
	upd(l);
	merge(l, l, r);
	merge(t, t, l);
}
 
void cut_paste(pnode &t, int x, int y){
	// cut the range [x, y] and paste to end
	pnode l=nullptr, r=nullptr;
	split(t, t, l, x-1);
	split(l, l, r, (y-x+1));
	merge(t, t, r);
	merge(t, t, l);
}
 
void shift(pnode &t, int x, int y){
	// shift to right in range [x, y]
	pnode l = nullptr, r = nullptr;
	split(t, t, l, x-1);
	split(l, l, r, y-x);
	pnode First = nullptr;
	split(r, r, First, 1);
	merge(r, r, l);
	merge(t, t, r);
	merge(t, t, First);
}
 
void reverse(pnode &t, int x, int y){
	// reverse in range [x, y]
	pnode l = nullptr, r = nullptr;
	split(t, t, l, x-1);
	split(l, l, r, y-x+1);
	l->rev ^= 1;
	merge(l, l, r);
	merge(t, t, l);
}
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cou n t.tie(0);
	srand(time(nullptr));
	pnode t = nullptr;
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		merge(t, t,  new node(a[i]));
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			reverse(t, l, r);
		}else{
			int l, r; cin >> l >> r;
			cout << get_sum(t, l, r) << '\n';
		}
	}
}