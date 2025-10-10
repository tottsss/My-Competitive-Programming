#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
int a[5001], dp[5001][5001][2], pref[5001];
 
 
int sum(int l, int r){
    return (pref[r] - pref[l-1]);
}
 
void solve(){
    int n; cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    for(int len = 1; len <= n; len++){
        for(int l = 1;l + len-1 <= n; l++){
            int r = l+len-1;
            if(len == 1){
                dp[l][r][0] = a[l];
            }else if(len == 2){
                dp[l][r][0] = max(a[l], a[r]);
            }else{
                dp[l][r][0] = max(a[l] + dp[l+1][r][1],
                                    a[r]+ dp[l][r-1][1]);
            }
            dp[l][r][1] = sum(l, r) - dp[l][r][0];
        }
    }
 
    // if(dp[1][n][0] > dp[1][n][1]) cout << 1;
    // else if(dp[1][n][0] < dp[1][n][1]) cout << 2;
    // else cout << 0;
    cout << max(dp[1][n][0], dp[1][n][1]);
}
 
main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}