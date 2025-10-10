#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
const int N = 1e5 + 1;
vector<int>  used(N, 0), g[N], G[N],  longest(N, 1), p(N, -1);
vector<int> topologic;
 
void dfs(int v){
    used[v] = 1;
    for(auto to : g[v]){
        if(used[to] == 0){
            dfs(to);
        }
    }
    topologic.push_back(v);
}
 
main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >>n >> m;
    for(int i = 0;i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        G[b].push_back(a);
    } 
    dfs(1);
  
    if(used[n] == 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(topologic.begin(), topologic.end());
    for(auto v : topologic){
        for(auto to : G[v]){
            if(longest[v] < longest[to]+1 and used[to] == 1){
                p[v] = to;
                longest[v] = longest[to]+1;
            }
            
        }
    }
    
    cout << longest[n]; cout << "\n";
    vector<int> path;
    for(int par = n; par != -1; par = p[par]){
        path.push_back(par);
    }
    for(int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
    return 0;
}