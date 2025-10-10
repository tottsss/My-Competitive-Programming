#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int M = 1e18;
struct node{
    long long sum, pref, suf, seg;
};
node tree[1<<22];
vector<int> lazy((1<<22));

node combine(node a, node b){
    node res;
    res.sum = a.sum + b.sum * 1LL;
    res.pref = max({res.sum, a.pref,  a.sum + b.pref}) * 1LL;
    res.suf = max({res.sum, b.suf, b.sum + a.suf}) * 1LL;
    res.seg = max({a.seg, b.seg, a.suf + b.pref}) * 1LL;
    return res;
}


void build(int v, int vl, int vr){
    if(vl == vr){
        tree[v] = {0LL, 0LL, 0LL, 0LL};
        return;
    }
    int mid = (vl + vr)>> 1;
    build(v<<1 | 1, vl, mid);
    build((v << 1) + 2, mid+1, vr);
    tree[v] = combine(tree[v<<1 | 1], tree[(v << 1) + 2]);
}

void push(int v, int vl, int vr){
    if(lazy[v] == M) return;
    if(lazy[v] >= 0){
        tree[v] = {lazy[v] * (vr-vl + 1),lazy[v] * (vr-vl + 1),
            lazy[v] * (vr-vl + 1), lazy[v] * (vr-vl + 1)};
    }else{
        tree[v] = {(lazy[v] * (vr-vl + 1)), 0, 0, 0};
    }
    if(vl != vr){
         lazy[(v<<1) | 1]= lazy[v];
         lazy[(v<<1) + 2]= lazy[v];
    }
    lazy[v] = M;
}

void modify(int l, int r, int x, int v, int vl, int vr){
    push(v, vl, vr);
    if(l > vr or vl > r) return;
    if(l <= vl and r >= vr){
        lazy[v] = x * 1LL;
        push(v, vl, vr);
        return;
    }
    int mid = (vl + vr) >>1;
    modify(l, r, x, (v<<1) | 1, vl, mid);
    modify(l, r, x, (v<<1) + 2, mid+1, vr);
    tree[v] = combine(tree[(v << 1) | 1], tree[(v << 1) + 2]);
}


main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lazy.assign((1<<21), M);
    int n, q; cin >> n >> q;  
    build(0,0, n-1);
    while(q--){
        int l, r, x; cin >> l >> r >> x;
        modify(l, r-1, x, 0, 0, n-1);
        cout << tree[0].seg << "\n";
    }
    
    return 0;
}