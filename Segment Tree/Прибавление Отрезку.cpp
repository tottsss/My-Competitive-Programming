#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long
int N = 1e5+1, siz = 1, NO = LLONG_MIN;

vector<int> tree, lazy;

void init(int n){
    while(n > siz) siz*= 2;
    tree.assign(4*siz-1, 0);
    lazy.assign(4*siz-1, 0);
}

void propogate(int v, int vl, int vr){
    tree[v] += lazy[v];
    if(vl != vr){
        lazy[2*v+1] += lazy[v];
        lazy[2*v+2] += lazy[v];
    }
    lazy[v] = 0;
}

void add(int l, int r, int x, int v, int vl, int vr){
    propogate(v, vl, vr);
    if(l > vr or vl > r) return;
    if(l <= vl and r >= vr){
        lazy[v]+= x;
        propogate(v, vl, vr);
        return;
    }
    int mid = (vl + vr) / 2;
    add(l, r, x, 2*v+1, vl, mid);
    add(l, r, x, 2*v+2, mid+1, vr);
    // tree[v] = min(tree[2*v+1], tree[2*v+2]);
}

int get(int pos, int v, int vl, int vr){
    propogate(v, vl, vr);
    if(vl == vr){
        return tree[v];
    }
    int mid = (vl + vr) / 2;
    if(pos <= mid) get(pos, 2*v+1, vl, mid);
    else get(pos, 2*v+2, mid+1, vr);
}

main(){
    int n, q; cin >> n >> q;
    init(n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, x; cin >> l >> r >> x;
            add(l, r-1, x, 0, 0, siz);
        }else{
            int pos; cin >> pos;
            cout << get(pos, 0, 0, siz) << "\n";
        }
    }
    return 0;
}