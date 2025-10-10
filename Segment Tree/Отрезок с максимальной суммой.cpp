#include <bits/stdc++.h>
  
using namespace std;
#define ff first
#define ss second
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back;
 
int a[(1<<20)];
int n, siz = 1;
struct node{
	int sum, pref, suf, seg;	
};
 
node tree[(1<<20)];
 
void init(int n){
	while(n>siz) siz*= 2;
	
}
 
 
node combine(node a, node b){
	node res; 
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum + b.pref);
	res.suf = max(b.suf, b.sum + a.suf);
	res.seg = max({ a.suf+b.pref, a.seg, b.seg});
	return res;
}
 
void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		tree[v].sum = x;
		tree[v].pref = tree[v].suf = tree[v].seg =max(0LL, x);
		
		return;
	}
	int mid = (vl + vr) / 2;
	if(mid >= pos){
		update(pos, x, 2*v, vl, mid);
	}else{
		update(pos, x, 2*v+1, mid+1, vr);
	}
	tree[v] = combine(tree[2*v], tree[2*v+1]);
}
 
main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    init(n);
    for(int i = 1;i <= n; i++){
    	cin >> a[i];
		update(i, a[i], 1, 1, siz);	
	}
	cout << tree[1].seg << "\n";
    while(q--){
    	int pos; cin >> pos;
    	int x ;cin >> x;
    	update(pos+1, x, 1, 1, siz);
			cout << tree[1].seg << "\n";
	}
    return 0;
}