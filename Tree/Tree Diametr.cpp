#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> g[n + 1];
    for(int i = 0;i < n-1; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    vector<int> dis(n + 1, -1);
    dis[1] = 0;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto to : g[v]){
            if(dis[to] == -1){
                dis[to] = dis[v] +1;
                q.push(to);
            }
        }
    }
    int mx_dist = -1;
    int vertex;
    for(int i = 1;i <= n; i++){
        if(mx_dist < dis[i]){
            mx_dist = dis[i];
            vertex = i;
        }
        dis[i] = -1;
    }
    dis[vertex] = 0;
    q.push(vertex);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto to : g[v]){
            if(dis[to] == -1){
                dis[to] = dis[v] +1;
                q.push(to);
            }
        }
    }
    for(int i = 1;i <= n; i++){
        if(mx_dist < dis[i]){
            mx_dist = dis[i];
            vertex = i;
        }
        dis[i] = -1;
    }
    cout << mx_dist;
}