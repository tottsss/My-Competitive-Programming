#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
int a[N+10];
int n, q;
struct node{
	int ans;
	int First, Last;
};
node t[4*N];
int lazy[4*N];
node merge(node A, node B){
	if(A.First == -1) return B;
	if(B.First == -1) return A;
	node C = {A.ans + B.ans + max(0LL, B.First - A.Last) - B.First, A.First, B.Last};
	return C;
}
void push(int v, int vl, int vr){
	if(lazy[v] == 0) return;
	t[v].ans+= lazy[v];
	t[v].Last+= lazy[v];
	t[v].First+= lazy[v];
	if(vl != vr){
		lazy[v<<1]+= lazy[v];
		lazy[v<<1|1]+= lazy[v];
	}
	lazy[v] = 0;
}

void add(int l, int r, int x, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v]+= x;
		push(v, vl,vr);
		return;
	}
	int mid = (vl + vr)>>1;
	add(l, r, x, v<<1, vl, mid);
	add(l, r, x, v<<1|1, mid+1, vr);
	t[v] = merge(t[v<<1], t[v<<1|1]);
}

void build(int v, int vl, int vr){
	if(vl == vr){
		t[v] = {a[vl], a[vl], a[vl]};
		return;
	}
	int mid = (vl+ vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	t[v] = merge(t[v<<1], t[v<<1|1]);
}

node get(int l, int r, int v, int vl, int vr){
	push(v, vl, vr);
	if(l > vr or vl > r) return {0, -1, -1};
	if(l <= vl and r >= vr) return t[v];
	int mid = (vl + vr)>>1;
	return merge(get(l, r,  v<<1, vl, mid), get(l, r, v<<1|1, mid+1, vr));
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while(q--){
		int type; cin >> type;
		int l, r; cin >> l >> r;
		if(type == 1){
			int k; cin >> k;
			add(l, r, k, 1, 1, n);
		}else{
			node Ans = get(l, r, 1, 1, n);
			cout << Ans.ans << '\n';	
//			cout << Ans.First << ", " << Ans.Last << '\n';
		}
	}	
	
	return 0;
}

