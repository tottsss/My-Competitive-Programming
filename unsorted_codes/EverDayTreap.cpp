#include "bits/stdc++.h"
using namespace std;
 #define int long long
 const int N = 1e6+1;
const int M = 1e9+7;
 
struct node{
	int key, cnt, prior;
	long long sum;
	node *l, *r;
	node(){
	}	
	node(int key) : key(key), sum(key), prior(rand()), cnt(1), l(nullptr), r(nullptr) {}
};
 
typedef node* pnode;
 
int cnt(pnode t){
	if(!t) return 0;
	return t->cnt;
}
 
int sum(pnode t){
	if(!t) return 0;
	return t->sum;
}
 
void upd(pnode t){
	if(!t) return;
	t->cnt = 1 + cnt(t->l) + cnt(t->r);
	t->sum = t->key + sum(t->l) + sum(t->r);
}
 
void split(pnode t, int x,  pnode&l, pnode&r){
	if(!t){
		l = NULL, r = NULL;
	}else if(t->key > x){
		split(t->l, x, l, t->l);
		r = t;
	}else{
		split(t->r, x, t->r, r);
		l = t;
	}
	upd(l); upd(r); upd(t);
}
 
 
void merge(pnode &t, pnode l, pnode r){
	if(!l) t = r;
	else if(!r) t = l;
	else if(l->prior > r->prior){
		merge(l->r, l->r, r);
		t = l;
	}else{
		merge(r->l, l, r->l);
		t = r;
	}
	upd(t);
}
 
void insert(pnode &t, pnode it){
	if(!t){
		t = it;
	}else if(it->prior > t->prior){
		split(t, it->key, it->l, it->r);
		t = it;
	}else{
		if(it->key < t->key) insert(t->l, it);
		else insert(t->r, it);
	}
	upd(t);
}
 
 
void erase(pnode&t, int key){
	if(t->key == key){
		merge(t, t->l, t->r);
	}else if(t->key > key) erase(t->l, key);
	else erase(t->r, key);
	upd(t);
}
 
int count(pnode t, int key){
	if(!t) return 0;
	if(t->key == key) return 1;
	else if(t->key > key) return count(t->l, key);
	else return count(t->r, key);
	upd(t);
}
 
int k_th(pnode t, int k){
	if(!t) return -1;
	if(cnt(t->l) + 1 == k){
		return t->key;
	}
	else if(cnt(t->l) >= k){
		return k_th(t->l, k);
	}
	return k_th(t->r, k-cnt(t->l)-1);
	upd(t);
}
 
 
void print(pnode t){
	if(!t) return;
	print(t->l);
	cout << t->key << " ";
	print(t->r);
}
 
pair<int, int> smaller_than(pnode &t, int key){
	pnode t2 = nullptr;
	split(t, key, t, t2);
	int sz = cnt(t);
	int sm = sum(t);
	merge(t, t, t2);
	return {sz, sm};
}
 
pair<int, int> bigger_than(pnode &t, int key){
	pnode t2 = nullptr;
	split(t, key, t, t2);
	int sz = cnt(t2);
	int sm = sum(t2);
	merge(t, t, t2);
	return {sz, sm};
}
 
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	pnode t = nullptr;
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0;i < n; i++) cin >> a[i];
	for(int i = 0;i < k; i++){
		insert(t, new node(a[i]));
	}
	int median, all;
	pair<int, int> smaller, bigger;
	for(int i = k; i < n; i++){
		all = 0;
		median = k_th(t, (k+1)>>1);
		smaller = smaller_than(t, median);
		bigger = bigger_than(t, median);
		all += abs((smaller.first * median ) - smaller.second);
		all += abs(bigger.second - (bigger.first*median));
		cout << all << " ";
		erase(t, a[i-k]);
		insert(t, new node(a[i]));
	}
	all = 0;
	median = k_th(t, (k+1)>>1);
	smaller = smaller_than(t, median);
	bigger = bigger_than(t, median);
	all += abs((smaller.first * median ) - smaller.second);
	all += abs(bigger.second - (bigger.first*median));
	cout << all;
	return 0;
}