#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
const int N = (1<<20);
int a[N];

struct node {
    int cnt[41];
    long long q;
    void init(){
        for(int i = 0;i < 41; i++) cnt[i] = 0; q = 0LL;
    }
};
node none;
long long siz = 1;
node tree[N];

void Init(int n){
    while(siz < n) siz*= 2;

}

node combine(node left, node right){
    node v = none;
    for(int i = 1;i < 41; i++){
        v.cnt[i] = left.cnt[i] + right.cnt[i];
        if(left.cnt[i] > 0 or right.cnt[i] > 0) v.q++;
    }
    return v;
}

void build(int v, int vl, int vr){
    if(vl == vr){
        tree[v] = none;
        tree[v].cnt[a[vl]] = 1;
        tree[v].q =1;
        return;
    }
    int mid =(vl + vr) / 2;
    build(2*v+1, vl, mid);
    build(2*v+2, mid+1, vr);
    tree[v] = combine(tree[2*v+1], tree[2*v+2]);
}

void update(int pos, int x, int  v, int vl, int vr){
    if(vl == vr){
        tree[v] = none;
        tree[v].cnt[x] = 1;
        tree[v].q =1;
        return;
    }
    int mid = (vl + vr) /2;
    if(pos <= mid) update(pos, x, 2*v+1, vl, mid);
    else update(pos, x, 2*v+2, mid+1, vr);
    tree[v] = combine(tree[2*v+1], tree[2*v+2]);
}

node modify(int l, int r, int v, int vl, int vr){
    if(l > vr or vl > r){
        return none;
    }
    if(l <= vl and r >= vr){
        return tree[v];
    }
    int mid = (vl + vr) /2;
    node L = modify(l, r, 2*v+1, vl, mid);
    node R = modify(l, r, 2*v+2, mid+1, vr);
    return combine(L, R);
}

main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    none.init();
    Init(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    build(0, 0, siz);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r; l--, r--;
            cout << modify(l, r, 0, 0, siz).q << "\n";
        }else{
            int pos, x; cin >> pos >> x; pos--;
            update(pos, x, 0, 0, siz);
        }
    }
    return 0;
}