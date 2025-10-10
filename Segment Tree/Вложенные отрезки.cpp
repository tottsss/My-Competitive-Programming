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

void update(int pos, int x, int v, int vl, int vr){
    if(vl == vr){
        tree[v] = x;
        return;
    }
    int mid = (vl + vr) / 2;
    if(pos <= mid) update(pos, x, 2*v+1, vl, mid);
    else update(pos, x, 2*v+2, mid+1, vr);
    tree[v] = tree[2*v+1] + tree[2*v+2];
}

int sum(int l, int r, int v, int vl, int vr){
    if(vl > r or l > vr) return 0LL;
    if(l <= vl and r >= vr) return tree[v];
    int mid = (vl + vr) / 2;
    int L = sum(l, r, 2*v+1, vl, mid);
    int R = sum(l, r, 2*v+2, mid+1, vr);
    return (L + R);
}

main(){
    int n; cin >> n;
    init(n+n);
    vector<int> a(n+n), ANS(n+1, 0);
    map<int, int> left;
    for(int i = 0;i < n+n; i++){
        cin >> a[i];
    }
    for(int i = 0;i < n+n; i++){
        if(left.count(a[i]) == false){
            left[a[i]] = i;
        }else{
            ANS[a[i]] = sum(left[a[i]], i, 0, 0, siz);
            update(left[a[i]], 1, 0, 0, siz);
        }
    }

    for(int i = 1;i <= n; i++){
        cout << ANS[i] << " ";
    }
    return 0;
}