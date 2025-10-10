#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long
vector<int> tree;
int siz = 1;

void init(int n){
    while(n > siz) siz*= 2;
    tree.assign(4*siz-1, 0);
}

int get(int pos, int v, int vl, int vr){
    if(vl == vr) return tree[v];
    int mid = (vl + vr) / 2;
    if(pos <= mid){
        return max(get(pos, 2*v+1, vl, mid), tree[v]);
    }else{
         return max(get(pos, 2*v+2, mid+1, vr), tree[v]);
     }
}

void add(int l, int r, int x, int v, int vl, int vr){
    if(l > vr or vl > r) return;
    if(l <= vl and r >= vr){
        tree[v] = max(tree[v], x);
        return;
    }
    int mid = (vl + vr) /2;
    add(l, r, x, 2*v+1, vl, mid);
    add(l, r, x, 2*v+2, mid+1, vr);
}

main(){
    int n, m; cin >> n >> m;
    init(n);
    while(m--){
        int type; cin >> type;
        if(type == 1){
            int l, r, x; cin >> l >> r >> x;
            add(l, r-1, x, 0, 0, siz);
        }else{
            int pos; cin >> pos;
            cout << get(pos, 0,0, siz) << "\n";
        }
    }
    return 0;
}