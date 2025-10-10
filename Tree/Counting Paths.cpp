#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
// #define int long long
const int N = 2e5+1;
const int LOG = 20;
int up[N][LOG];
vector<int> g[N], depth(N, 0), value(N, 0);
void dfs(int v, int par){
    for(auto to : g[v]){
        if(to == par) continue;
        depth[to] = depth[v] +1 ;
        up[to][0] = v;
        for(int i = 1;i < LOG; i++){
            up[to][i] = up[up[to][i-1]][i-1];
        }
        dfs(to, v);
    }
}
void dfs_ans(int v, int par){
    int sum = value[v];
    for(auto to : g[v]){
        if(to == par) continue;
        dfs_ans(to, v);
        sum+= value[to];
    }
    value[v] = sum;
}
 
int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--){
        if((k & (1<<i) )){
            a = up[a][i];
        }
    }
    if(a == b) return a;
    for(int i = LOG-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
 
main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1;i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    depth[1] = 0;
    while(m--){
        int a, b; cin >> a >> b;
        value[a]++;
        value[b]++;
        int LCA = lca(a, b);
        value[LCA]--;
        LCA = up[LCA][0];
        if(LCA != 0){
            value[LCA]--;
        } 
    }
    dfs_ans(1, 1);
    for(int i = 1;i <= n; i++){
        cout << value[i] << " ";
    }
    return 0;
}