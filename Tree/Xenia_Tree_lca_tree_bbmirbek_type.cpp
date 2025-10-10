# include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

# define pb push_back
# define fr first
# define sc second
# define mk make_pair
#define sz(s) ((int) s.size())

using namespace std;

const long long linf = 1e18 + 7;
const int inf = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long ll;

int n, m;
int depth[N], used[N], h[N], pr[N];
int tin[N], tout[N], timer, p[18][N];
int ans[N];
vector <int> g[N];

void dfs(int v, int par){
      tin[v] = ++ timer;
      p[0][v] = par;
      for(int i = 1; i <= 17; i ++)
            p[i][v] = p[i - 1][p[i - 1][v]];
      for(int to : g[v]){
            if(to == par) continue;
            depth[to] += depth[v] + 1;
            dfs(to, v);
      }
      tout[v] = ++ timer;
}

int dfs(int v, int pr, int &c, int sz){
      int sum = 1;
      for(int to : g[v]){
            if(used[to] || to == pr) continue;
            sum += dfs(to, v, c, sz);
      }
      if(c == -1 && (sum * 2 >= sz || pr == -1)){
            c = v;
      }
      return sum;
}

void build(int v, int sz, int last, int len = 0){
      int centroid = -1;
      dfs(v, -1, centroid, sz);
      used[centroid] = 1;
      pr[centroid] = last;
      h[centroid] = len;
      for(int to : g[centroid]){
            if(used[to]) continue;
            build(to, sz >> 1, centroid, len + 1);
      }
}

bool upper(int a, int b){
      return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
      if(upper(a, b)) return a;
      if(upper(b, a)) return b;
      for(int i = 17; i >= 0; i --){
            if(!upper(p[i][a], b)) a = p[i][a];
      }
      return p[0][a];
}

int dist(int a, int b){
      return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main(){
      cin >> n >> m;

      for(int i = 1; i < n; i ++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
      }

      dfs(1, 1);
      build(1, n, -1);
      for(int i = 1; i <= n; i ++)
            ans[i] = inf;

      int a, b;

      a = b = 1;

      while(a != -1){
            ans[a] = min(ans[a], dist(a, b));
            a = pr[a];
      }

      while(m --){
            int type, v;
            scanf("%d %d", &type, &v);
            if(type == 1){
                  int x = v;
                  while(v != -1){
                        ans[v] = min(ans[v], dist(x, v));
                        v = pr[v];
                  }
            } else {
                  int x = v;
                  int mn = inf;
                  while(v != -1){
                        mn = min(mn, ans[v] + dist(x, v));
                        v = pr[v];
                  }
                  printf("%d\n", mn);
            }
      }
}
