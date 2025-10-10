#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

struct Node{
	Node* l, *r;
	int sum;
	Node(Node *ll, Node* rr){
		l = ll, r = rr;
		sum = 0;
		if(l) sum+= l->sum;
		if(r) sum+= r->sum;
	}
	Node(int x){
		l = NULL, r = NULL, sum = x;
	}
};

typedef Node* pNode;

vector<pNode> versions;
int n, q;
int a[200005];
pNode build(int vl, int vr){
	if(vl == vr){
		return new Node(a[vl]);
	}
	int mid = (vl + vr)>>1;
	return new Node(build(vl, mid), build(mid+1, vr));
}

pNode update(pNode &t, int pos, int x, int vl, int vr){
	if(vl == vr){
		return new Node(x);
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) return new Node(update(t->l, pos, x, vl, mid), t->r);
	else return new Node(t->l, update(t->r, pos, x, mid+1, vr));
}

int get_sum(pNode &t, int l, int r, int vl, int vr){
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr) return t->sum;
	int mid = (vl + vr)>>1;
	return get_sum(t->l, l, r, vl, mid) + get_sum(t->r, l, r, mid+1, vr);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	cin >> q;
	versions.push_back(build(1, n));
	while(q--){
		int type; cin >> type;
		int vr; cin >> vr;
		if(type == 1){
			int pos, x; cin >> pos >> x;
			pNode NEW = versions[vr];
			versions.push_back(NEW);
			versions.back() = update(versions.back(), pos, get_sum(versions[vr], pos, pos, 1, n) + x, 1, n);
		}else{
			int l, r; cin >> l >> r;
			cout << get_sum(versions[vr], l, r, 1, n) << '\n';
		}
	}
	return 0;
}

