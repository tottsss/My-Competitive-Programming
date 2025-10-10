#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
vector<int> children[N];
vector<int> subtree(N, 1);
void dfs(int v){
    for(auto to : children[v]){
        
        dfs(to);
        subtree[v]+= subtree[to];
    }
}
 
main(){
    int n; cin >> n;
    for(int i = 2;i <= n; i++){
        int par; cin >> par;
        children[par].push_back(i);
    }
 
    dfs(1);
 
    for(int i = 1;i <= n; i++){
        cout << subtree[i]-1 << " ";
    }
    return 0;
}