#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long
const int N = 1e5;
int tree[4*N];
int n, q;



void upd(int pos, int x,  int v, int vl, int vr){
    if(vl == vr){
    	tree[v] = x;
    	return;
	}
    int mid = (vl + vr)>>1;
    if(mid >= pos) upd(pos, x, v<<1, vl, mid);
    else upd(pos, x, v<<1|1, mid+1, vr);
     tree[v] = tree[2*v]+ tree[2*v+1];
}

int get(int l, int r,  int v, int vl, int vr){
    if(l > vr or vl > r) return 0;
    if(l <= vl and r >= vr) return tree[v];
    int mid = (vl + vr)>>1;
    int L = get(l, r, 2*v, vl, mid);
    int R = get(l, r, 2*v+1, mid+1, vr);
    return L+R;
}

main(){
    cin >> n >> q;
    while(q--){
    	int t; cin >> t;
    	if(t == 2){
    		int pos, x; cin >> pos >> x;
    		upd(pos, x, 1, 1, n);
		}else{
			int l, r; cin >> l >> r;
			cout << get(l, r, 1, 1, n) << '\n';
		}
	}
    return 0;
}