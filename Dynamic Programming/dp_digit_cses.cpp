#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define pb push_back
#define ln '\n'
#define int long long
 
template <class _T>
bool chmin(_T &x, const _T &y){
    bool flag = false;
    if ( x > y ){
        x = y; flag |= true;
    }
    return flag;
}
 
template <class _T>
bool chmax(_T &x, const _T &y){
    bool flag = false;
    if ( x < y ){
        x = y; flag |= true;
    }
    return flag;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    auto f = [&](int n){
        if ( n < 0 ){
            return 0ll;
        }
        string s = to_string(n);
        reverse(all(s));
        int m = (int)s.size(), dp[m + 1][10][2];
        memset(dp, 0, sizeof(dp));
        for ( int i = 0; i <= 9; i++ ){
            dp[1][i][s[0] - '0' < i] = 1;
        }
        for ( int i = 2; i <= m; i++ ){
            int d = s[i - 1] - '0';
            for ( int j = 0; j <= 9; j++ ){
                for ( int k = 0; k <= 9; k++ ){
                    if ( k == j ){
                        continue;
                    }
                    for ( auto f: {0, 1} ){
                        bool flag = (j > d) or (j == d & f);
                        dp[i][j][flag] += dp[i - 1][k][f];
                    }
                }
            }
        }
        int cnt = 0;
        for ( int i = 1; i <= m; i++ ){
            for ( int j = (i != 1); j <= 9; j++ ){
                if ( i < m ){
                    cnt += dp[i][j][0] + dp[i][j][1];
                } else cnt += dp[i][j][0];
            }
        }
        return cnt;
    };
    int a, b; cin >> a >> b;
//    cout << f(b) << ' ' << f(a - 1) << '\n';
    cout << f(b) - f(a - 1);
 
    cout << '\n';
}