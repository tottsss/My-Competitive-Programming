#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;
 
#define int long long
const int M = 1e9 + 7;
 
 
main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    vector< vector<int> > dp(n, vector<int>(m + 1, 0));
    if(a[0] == 0){
        for(int j = 1;j <= m; j++){
            dp[0][j] = 1;
        }
    }else{
        dp[0][a[0]] = 1;
    }
    function<bool(int, int)> in=[&](int i, int j){
        if(i>=0 and i < n and j > 0 and j <= m ) return true;
        return false;
    };
    for(int i = 1;i < n; i++){
        if(a[i] == 0){
        for(int j = 1;j <= m; j++){
            dp[i][j]+= dp[i-1][j];
            if(in(i-1, j-1)) dp[i][j]+= dp[i-1][j-1];
            if(in(i-1, j+1)) dp[i][j]+= dp[i-1][j+1];
            dp[i][j]%= M;
        }
        }else{
            dp[i][a[i]]+= dp[i-1][a[i]];
            if(in(i-1, a[i]-1)) dp[i][a[i]]+= dp[i-1][a[i]-1];
            if(in(i-1, a[i]+1)) dp[i][a[i]]+= dp[i-1][a[i]+1];
            dp[i][a[i]]%= M;
        }
    }
    int sum = 0;
    for(int j = 1;j < m+1; j++){
        sum = (sum + dp[n-1][j]) %M;
    }
    cout << sum << endl;
    return 0;
}