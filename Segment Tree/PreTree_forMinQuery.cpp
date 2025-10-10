#include <bits/stdc++.h>

using namespace std;

struct PreTree {  
  struct Node { int v, dp; };
  
  int n;
  vector<Node> T;

  PreTree(int n) : n(n), T(n) {}

  void pull(int b, int e) {
    int m = (b + e + 1) / 2;
    T[b].dp = T[b].v;
    if (b + 1 < m) T[b].dp = min(T[b].dp, T[b + 1].dp);
    if (m < e) T[b].dp = min(T[b].dp, T[m].dp);
  }

  void update(int b, int e, int pos, int v) {
    if (b == pos) {
      T[b].v = v;
    } else {
      int m = (b + e + 1) / 2;
      if (pos < m) update(b + 1, m, pos, v);
      else update(m, e, pos, v);
    }
    pull(b, e);
  }

  int query(int b, int e, int l, int r) {
    l = max(l, b); r = min(r, e);
    if (l >= r) return 2e9;
    if (b == l && e == r) return T[b].dp;
    int m = (b + e + 1) / 2;
    int ans = (b == l ? T[b].v : 2e9);
    ans = min(ans, query(b + 1, m, l, r));
    ans = min(ans, query(m, e, l, r));
    return ans;
  }

  void build(int b, int e) {
    if (b >= e) return;
    int m = (b + e + 1) / 2;
    build(b + 1, m);
    build(m, e);
    pull(b, e);
  }

  void Update(int pos, int val) { 
    update(0, n, pos, val); 
  }
  int Query(int l, int r) { 
    return query(0, n, l, r); 
  }
  void Build() { 
    build(0, n); 
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  PreTree pt(n);
  for (int i = 0; i < n; ++i)
    cin >> pt.T[i].v;
  pt.Build();
  for (int i = 0; i < m; ++i) {
    int typ, a, b; cin >> typ >> a >> b;
    if (typ == 1) pt.Update(a, b);
    else cout << pt.Query(a, b) << '\n';
  }
  return 0;
}