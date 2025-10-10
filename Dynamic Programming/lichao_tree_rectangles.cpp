#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int inf = 1e9 + 50;
struct Line{
	int k, b;
	Line(int k = 0, int b = 0) : k(k), b(b) {}
};

int F(Line &a, int x){
	return a.k*x + a.b;
}
struct LiChao{
	struct Node{
		Line k;
		Node *l, *r;
		Node(){
			l = nullptr, r = nullptr;
		}
	};
	int n;
	Node *root;
	LiChao(int n) : n(n), root(nullptr) {}
	void addLine(Node *&p, int l, int r, Line &a){
		if(!p) p = new Node();	
		int mid = (l + r) / 2;
		int l_side = F(a, l) > F(p->k, l);
		int m_side = F(a, mid) > F(p->k, mid);
		if(m_side) p->k = a;
		if(l == r-1) return;
		if(l_side == m_side){
			addLine(p->r, mid, r, a);
		}else{
			addLine(p->l, l, mid, a);
		}
	}
	void addLine(Line a){
		addLine(root, 0, n, a);
	}
	int get(Node *&p, int l, int r, int x){
		if(!p) return 0LL;
		if(l == r-1){
			return F(p->k, x);
		}
		int mid = (l + r) / 2;
		if(mid > x){
			return max(F(p->k, x), get(p->l, l, mid, x));
		}else{
			return max(F(p->k, x), get(p->r, mid, r, x));
		}
	}
	
	int get(int x){
		return get(root, 0, n, x);
	}
	
};

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x[n], y[n], a[n];
	for(int i = 0;i < n; i++){
		cin >> x[i] >> y[i] >> a[i];
	}
	vector<int> p(n);
	iota(all(p), 0);
	sort(all(p), [&](int i, int j){
		return x[i] < x[j];
	});
	
	LiChao lch(inf);
	lch.addLine(Line(0, 0));
	int ans = 0;
	for(int cur : p){
		int mx = lch.get(y[cur]);
//		cout << mx << '\n';
		int val = lch.get(y[cur]) + x[cur]*y[cur] - a[cur];
		ans = max(ans, val);
		lch.addLine(Line(-x[cur], val));
	}
	cout << ans;
	return 0;
}

