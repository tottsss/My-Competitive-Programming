#include <bits/stdc++.h>
using namespace std;
// 
#define int long long
 
 
 
main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k = (n * n) / 2;
    k++;
    int l = 0, r = 1e18;
 
    function<bool(int)> good=[&](int m){
        int cnt = 0;
        for(int i = 1;i <= n; i++){
            cnt+= min(n, m/i);
        }
        if(cnt >= k) return true;
            return false;
    };
 
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(good(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}