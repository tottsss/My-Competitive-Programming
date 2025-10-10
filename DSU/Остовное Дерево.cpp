#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
 #define int long long
const int N = 2e5 + 1;
vector<int> par(N);

void make_set(int v){
    par[v] = v;
} 

int find_set(int v){
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    par[b] = a;
}
void solve(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1;i <= n; i++){
        make_set(i);
    }
    vector< pair<int, pair<int, int> > > edge;
    for(int i = 1;i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    vector<int> cost;
    int S = 0;
    sort(edge.begin(), edge.end());
    for(auto to : edge){
        int c = to.ff;
        int a = to.ss.ff;
        int b = to.ss.ss;
        if(find_set(a) == find_set(b)) continue;
        union_set(a, b);
        cost.push_back(c);
        S+= c;
    }
    //sort(cost.begin(), cost.end());

    cout << S;
}

main(){
    int T=1; 
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}