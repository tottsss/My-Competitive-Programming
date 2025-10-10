#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        sum^= a[i];
    }
    if(sum == 0) cout << "second";
    else cout << "first";
}
 
main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int T = 1; 
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }
    return 0;
}