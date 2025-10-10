#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long
int N = 1e5+1, siz = 1;
vector<int> odd, even,  a(4*N,0);

void init(int n){
    while(n > siz) siz*= 2;
    odd.assign(4*siz-1, 0);
    even.assign(4*siz-1, 0);
}

void build(int v, int vl, int vr){
    if(vl == vr){
        if(vl%2==0) even[v] = a[vl];
        else odd[v] = a[vl];
        return;
    }
    int mid = (vl + vr) / 2;
    build(2*v+1, vl, mid);
    build(2*v+2, mid+1, vr);
    odd[v] = odd[2*v+1] + odd[2*v+2];
    even[v] = even[2*v+1] + even[2*v+2];
}

void update_odd(int pos, int x, int v, int vl, int vr){
    if(vl == vr){
        odd[v] = x;
        return;
    }
    int mid = (vl + vr) / 2;
    if(pos <= mid) update_odd(pos, x, 2*v+1, vl, mid);
    else update_odd(pos, x, 2*v+2, mid+1, vr);
    odd[v] = odd[2*v+1] + odd[2*v+2];
}

int sum_odd(int l, int r, int v, int vl, int vr){
    if(l > vr or vl > r) return 0;
    if(l <= vl and r >= vr) return odd[v];
    int mid = (vl + vr) / 2;
    int L = sum_odd(l, r, 2*v+1, vl, mid);
    int R = sum_odd(l, r, 2*v+2, mid+1,vr);
    return (L + R);
}

void update_even(int pos, int x, int v, int vl, int vr){
     if(vl == vr){
        even[v] = x;
        return;
    }
    int mid = (vl + vr) / 2;
    if(pos <= mid) update_even(pos, x, 2*v+1, vl, mid);
    else update_even(pos, x, 2*v+2, mid+1, vr);
    even[v] = even[2*v+1] + even[2*v+2];
}

int sum_even(int l, int r, int v, int vl, int vr){
    if(l > vr or vl > r) return 0;
    if(l <= vl and r >= vr) return even[v];
    int mid = (vl + vr) / 2;
    int L = sum_even(l, r, 2*v+1, vl, mid);
    int R = sum_even(l, r, 2*v+2, mid+1,vr);
    return (L + R);
}

main(){
    int n; cin >> n;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    init(n);
    build(0, 0, siz);
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r; l--, r--;
            if(l%2 == 0)
            cout << -sum_odd(l, r, 0, 0, siz) + (sum_even(l, r, 0, 0, siz));
            else cout << sum_odd(l, r, 0, 0, siz) + -(sum_even(l, r, 0, 0, siz));
            cout << "\n";
        }else{
            int pos, x; cin >> pos >> x;
            pos--;
            if(pos%2==0) update_even(pos, x, 0, 0, siz);
            else update_odd(pos, x, 0, 0, siz);
        }
    }
    return 0;
}