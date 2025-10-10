#include <bits/stdc++.h>
using namespace std;
  #define int long long
 
 
void solve(){
    int n, m, k; cin >> n >> m >> k;
    multiset< pair<int, int> > q;
    vector< pair<int, int> >g[n+1];
    for(int i = 0;i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    q.insert({0, 1});
   	vector<int> cost, cnt(n + 1, 0);
    while(q.empty() == false and cnt[n] < k){
        pair<int, int> u = *q.begin();
        int w = u.first; int v = u.second;
        q.erase(q.begin());
        cnt[v]++;
        if(v == n){
            cost.push_back(w);
            
        }
        if(cnt[v] <= k){
            for(auto to : g[v]){
                q.insert({w + to.second, to.first});
            }
        }
    }
    sort(cost.begin(), cost.end());
    for(auto to : cost) cout << to << " ";
}
 
main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}