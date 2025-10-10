#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define pb push_back
#define ln '\n'
#define int long long
 
using i64 = long long;
 
template <class F, class _S>
bool chmin(F &u, const _S &v){
    bool flag = false;
    if ( u > v ){
        u = v; flag |= true;
    }
    return flag;
}
 
template <class F, class _S>
bool chmax(F &u, const _S &v){
    bool flag = false;
    if ( u < v ){
        u = v; flag |= true;
    }
    return flag;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int h, w; cin >> h >> w;
    if ( h > w ) swap(h, w);
    int ans = h * w;
    for ( int i = h - 1; i > 1; i-- ){
        ans += w * i;
    }
    if ( h == 1 ) ans = 0;
    cout << ans + (w * (w + 1) / 2 + w - 1) * h;
 
    cout << '\n';
}