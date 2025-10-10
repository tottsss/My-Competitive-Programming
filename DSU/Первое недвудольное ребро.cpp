#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long

const int N = 3e5+1;
int par[N], siz[N], len[N];

pair<int, int> find_set(int v){
    if(v == par[v]){
        return {v, 0};
    }
    pair<int, int> val = find_set(par[v]);
    par[v] = val.ff; 
    len[v] = (len[v] + val.ss) % 2;
    return {par[v], len[v]};
}

void union_set(pair<int, int> A, pair<int, int> B){
    if(siz[A.ff] < siz[B.ff]) swap(A, B);
    par[B.ff] = A.ff;
    siz[A.ff]+= siz[B.ff];
    len[B.ff] = (1+A.ss+B.ss) % 2;
}


main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1;i <= n; i++){
        len[i] = 0, siz[i] = 1, par[i] = i;
    }
    for(int i = 1;i <= m; i++){
        int a, b; cin >> a >> b;
        pair<int, int> A = find_set(a);
        pair<int, int> B = find_set(b);
        if(A.ss == B.ss and A.ff == B.ff){
            cout << i;
            return 0;
        }
        union_set(A,B);
    }
    // cout << 't';/
    cout << -1;
    return 0;
}