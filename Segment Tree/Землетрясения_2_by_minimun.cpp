#include <bits/stdc++.h>

//author: boy_of_kutbilim

using namespace std;

struct SegmentTreeMin {
   int n;
   vector<int> t;
   SegmentTreeMin(int n) : n(n), t((n << 2) + 1, INT_MAX) {}
   void update(int i, int x, int v, int vl, int vr) {
      if (vl == vr) {
         t[v] = x;
      } else {
         int vm = (vl + vr) >> 1;
         if (i <= vm)
            update(i, x, v << 1, vl, vm);
         else
            update(i, x, v << 1 | 1, vm + 1, vr);
         t[v] = min(t[v << 1], t[v << 1 | 1]);
      }
   }
   int query(int l, int r, int p, int v, int vl, int vr) {
      if (l > vr || vl > r || t[v] > p) return 0;
      else if (vl == vr) {
         t[v] = INT_MAX;
         return 1;
      }
      else {
         int vm = (vl + vr) >> 1;
         int L = query(l, r, p, v << 1, vl, vm);
         int R = query(l, r, p, v << 1 | 1, vm + 1, vr);
         t[v] = min(t[v << 1], t[v << 1 | 1]);
         return L + R;
      }
   }
   void update(int i, int x) {
      update(i, x, 1, 0, n - 1);
   }
   int query(int l, int r, int p) {
      return query(l, r, p, 1, 0, n - 1);
   }
};

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n, q;
   cin >> n >> q;
   SegmentTreeMin st(n);

   while (q --) {
      int t;
      cin >> t;
      if (t == 1) {
         int i, v;
         cin >> i >> v;
         st.update(i, v);
      } else {
         int l, r, p;
         cin >> l >> r >> p;
         cout << st.query(l, r - 1, p) << '\n';
      }
   }

   return 0;
}