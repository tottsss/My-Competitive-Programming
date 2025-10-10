#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 1;
vector<int> a(N);
int siz = 1LL;
struct node{
    int seg, pref, suf, sum;
};
 
 
 
 
node ZERO = {0LL, 0LL, 0LL, 0LL};
vector<node>  tree(4*N);
 
node combine(node a, node b){
    return {
        max({a.seg, b.seg, a.suf + b.pref}),
        max(a.pref, a.sum + b.pref),
        max(b.suf, b.sum + a.suf),
        a.sum+b.sum
    };
}
 
void init(int n){
    while(siz < n) siz*= 2;
  
}
 
node one_element(int x){
    return{
        max(0LL, x), 
        max(0LL, x), 
        max(0LL, x),
         x
    };
}
 
void build(int v, int vl, int vr){
    if(vl == vr){
        if(vl < N)
        tree[v] = one_element(a[vl]);
    }else{
        int mid = (vl + vr) / 2;
        build(2*v+1, vl, mid);
        build(2*v+2, mid+1, vr);
         tree[v] = combine(tree[2*v+1], tree[2*v+2]);
    }
 
}
 
void update(int pos, int x, int v, int vl, int vr){
    if(vl == vr){
        tree[v] = one_element(x);
        
    }else{
        int mid = (vl + vr) / 2;
        if(mid >= pos){
            update(pos, x, 2*v+1, vl, mid);
        }else update(pos, x, 2*v+2, mid+1, vr);
 
        tree[v] = combine(tree[2*v+1], tree[2*v+2]);
    }
}
 
main(){
    ios::sync_with_stdio(0); 
cin.tie(0);
    cout.tie(0); 
    int n, q; cin >> n >> q;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    init(n);
    build(0, 0, siz);
    //cout << tree[0].seg << "\n";
    for(int j = 1;j <= q; j++){
        int pos, x; cin >> pos >> x;
        pos--;
        update(pos, x, 0, 0, siz);
        cout << tree[0].seg << "\n";
    }
    return 0;
}