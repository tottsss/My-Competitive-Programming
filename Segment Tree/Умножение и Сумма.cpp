#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+1, MOD = 1e9+7;

int siz = 1;
vector<int> tree, lazy;
void init(int n){
    while(n > siz) siz*= 2;
    tree.assign(4*siz, 0);
    lazy.assign(4*siz, 1);
}

void propogate(int v, int vl, int vr){
    tree[v]*= lazy[v]%MOD; tree[v]%= MOD;
    if(vl != vr){
        lazy[2*v+1] *= lazy[v]%MOD;
        lazy[2*v+1] %= MOD;
        lazy[2*v+2] *= lazy[v]%MOD;
        lazy[2*v+2] %= MOD;
    }
    lazy[v] = 1;
}

void build(int v, int vl, int vr){
    if(vl == vr){
        tree[v] = 1;
        return;
    }
    int mid = (vl + vr) / 2;
    build(2*v+1, vl, mid);
    build(2*v+2, mid+1, vr);
    tree[v] = tree[2*v+1] + tree[2*v+2];
}

int sum(int l, int r, int v, int vl, int vr){
    propogate(v, vl, vr);
    if(l > vr or vl > r) return 0LL;
    if(l <= vl and r >= vr) return tree[v];
    int mid = (vl + vr) / 2;
    int L = sum(l, r, 2*v+1, vl, mid) % MOD;
    int R = sum(l, r, 2*v+2, mid+1, vr) % MOD;
    return (L + R)%MOD;
}

void mult(int l, int r, int x, int v, int vl, int vr){
    propogate(v, vl, vr);
    if(l > vr or vl > r) return;
    if(l <= vl and r >= vr){
        lazy[v] = (lazy[v] * x)%MOD;
        propogate(v, vl, vr);
        return;
    }
    int mid = (vl + vr) / 2;
    mult(l, r, x, 2*v+1, vl, mid);
    mult(l, r, x, 2*v+2, mid+1, vr);
    tree[v] = (tree[2*v+1] + tree[2*v+2]) % MOD;
}

 main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    init(n);
    build(0, 0, siz);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l,r, x; cin >> l >> r >> x;
            mult(l, r-1, x, 0, 0, siz);
        }else{
            int l, r; cin >> l >> r;
            cout << sum(l, r-1, 0, 0, siz) << "\n";
        }
    }
    return 0;
}
