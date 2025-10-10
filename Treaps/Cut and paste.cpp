#include <bits/stdc++.h>
 
using namespace std;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937_64 gen(gen_seed);	
struct node {
	int  prior, cnt;
	char key;
	node * l, * r;
	node() {}
	node(char key) : key(key), prior(gen()), cnt(1), l(nullptr), r(nullptr) {}
};
typedef node * pnode;
 
int cnt(pnode t) {	
	return (t ? t->cnt : 0);
}
 
void upd(pnode t) {
	if (t) {
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
	}
}
  
void merge(pnode & t, pnode l, pnode r) {
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
	if (!t){
		l= NULL, r = NULL;
		return;
	}else if (len <= cnt(t->l))
		split(t->l, l, t->l, len), r = t;
	else
		split(t->r, t->r, r, len - cnt(t->l) - 1), l = t;
	upd(l), upd(r), upd(t);
}
 
void print(pnode t) {
	if (!t) return;
	print(t->l);
	cout << t->key;
	print(t->r);
}
 
 
void cut_paste(pnode &t, int x, int y){
	pnode l=nullptr, r=nullptr;
	split(t, t, l, x-1);
	split(l, l, r, (y-x+1));
	merge(t, t, r);
	merge(t, t, l);
}
 
 
 
main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pnode t = nullptr, t2 = nullptr;
	int n;
	cin >> n;
	int q; cin >> q;
	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		merge(t, t,	 new node(ch));
	}
//	while(q--){
//		int type; cin >> type;
//		if(type == 2){
//			// get the sum in range [x, y]
//			int l, r; cin >> l >> r;
//			cout << get_sum(t, l, r) << '\n';
//		}else{
//			// update at position pos to x
//			update_pos(t, x, pos, pos);
//		}
//	}
	while(q--){
		int l, r; cin >> l >> r;
		cut_paste(t, l, r);
	}
	print(t);
	return 0;
}