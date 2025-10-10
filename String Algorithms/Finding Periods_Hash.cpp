#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
//===========================================
const int MAX = 1e6+5;
const int P = 31;
ll pw[MAX], hsh[MAX];

inline ll h(int l, int r){ return (hsh[r]-hsh[l-1]+MOD)*pw[MAX-r]%MOD; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    pw[0] = 1; for (int i = 1; i < MAX; i++) pw[i] = pw[i-1]*P%MOD;
    string s; cin >> s;
    int n = (int)s.length(); s = '#'+s;
    for (int i = 1; i <= n; i++) hsh[i] = (hsh[i-1]+pw[i-1]*(s[i]-'a'+1))%MOD;
    for (int i = 1; i <= n; i++){
        bool good = true;
        for (int j = 1; j <= n; j+=i){
            if (j+i-1 <= n && h(j, j+i-1) != h(1, i)){ good = false; break; }
            else if (j+i-1 > n && h(j, n) != h(1, n-j+1)) good = false;
        }
        if (good) cout << i << " ";
    }
}