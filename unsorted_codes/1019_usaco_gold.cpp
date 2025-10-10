;lidhfskdjjhSLKJBB lksd fsdliuSg lihduzgblkv 	
sdgkjlsd hlds 
	hdfhlsdgjkld#include "bits/stdc++.h"

using namespace std;

vector <vector <int> > g;
vector <int> strik;
int k, flag;
string ans;
void dfs(int v, int p) {
  vector <int> child;
  for(auto u : g[v]) {
    if(u == p) continue;
    dfs(u, v);
    if(flag) return;
    child.push_back(u);
  }
  if(child.size() == 1) {
    strik[v] = strik[child[0]] + 1;
    strik[v] %= k;
  }else if(child.size() == 0) {
    strik[v] = 0;
  }else {
    for(auto i : child) {
      strik[i] ++;
      strik[i] %= k;
    }
    map <int,int> remind;
    for(auto i : child) {
      if(strik[i] == 0) continue;
      if(remind[k-strik[i]] > 0) {
        remind[k-strik[i]]--;
      }else remind[strik[i]] ++;
    }
    int f = -1;
    for(int i = 0; i < k; i ++) {
      if(remind[i] > 1) {
        ans += '0';
        flag = 1;
        return;
      }
      if(remind[i] == 1) {
        if(f != -1) {
          ans += '0';
          flag = 1;
          return;
        }
        f = i;
      }
    }
    if(f == -1) strik[v] = 0;
    else strik[v] = f;
  }
}

signed main () {
  ifstream cin ("deleg.in");
  ofstream cout("deleg.out");
  int n;
  cin >> n;
  g.resize(n);
  strik.resize(n);
  for(int i = 0; i < n - 1; i ++) {
    int u, v;
    cin >> u >> v;
    u --, v --;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> mp((int)n, 0);
  for(k=1; k < n; k ++) {
    if(mp[k]==1) {
      ans += '0';
      continue;
    }
    if((n-1)%k!=0) {
      ans += '0';
      continue;
    }

    flag = 0;
    dfs(0, -1);
    if(flag) {
      for(int i = 1; i * k < n; i ++) mp[i*k]=1;
      continue;
    }
    if(strik[0] % k == 0){
      ans += '1';
    }
    else {
      ans += '0';
      for(int i = 1; i * k < n; i ++) mp[i*k]=1;
    }
    end:;
  }
  // reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}