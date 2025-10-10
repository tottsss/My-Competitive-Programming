#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <chrono>
#include <random>
 
using ll = long long;
 
int const nmax = 200000;
int const lgmax = 20;
std::vector<int> g[5 + nmax];
 
//These are for the real tree
int parent[5 + nmax], level[5 + nmax];
int id[5 + nmax];
 
//There are for the virtual tree
int revid[5 + nmax / lgmax], level2[5 + nmax / lgmax];
int far[1 + lgmax][5 + nmax / lgmax];
 
void dfs(int node, int currParent) {
  if(0 < id[node]) {
    far[0][id[node]] = currParent;
    currParent = id[node];
  }
 
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    level[to] = level[node] + 1;
    dfs(to, currParent);
  }
}
 
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
 
  std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  std::cin >> n >> q;
 
  for(int i = 2;i <= n; i++) {
    std::cin >> parent[i];
    g[parent[i]].push_back(i);
  }
 
  for(int i = 1;i <= n / lgmax; i++)
    id[i] = i;
 
  shuffle(id + 1, id + n + 1, rng);
  
  level[1] = 1;
  dfs(1, 0);
  
  for(int i = 1;i <= n; i++)
    if(0 < id[i]) {
      revid[id[i]] = i;
      level2[id[i]] = level[i];
    }
 
 
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n / lgmax; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
    
  for(int i = 1; i <= q; i++) {
    int node, k;
    std::cin >> node >> k;
    if(level[node] <= k)
      std::cout << -1 << '\n';
    else {
      while(0 < k && id[node] == 0) {
        node = parent[node];
        k--;
      }
 
      if(0 < k) {
        node = id[node];
        for(int h = lgmax; 0 <= h; h--)
          if(level2[node] - level2[far[h][node]] <= k) {
            k -= level2[node] - level2[far[h][node]];
            node = far[h][node];
          }
        node = revid[node];
      }
      while(0 < k) {
        node = parent[node];
        k--;
      }
      std::cout << node << '\n';
    }
  }
  return 0;
}