#include <bits/stdc++.h>
 
using namespace std;
 
int t[2049][2049], N = 1024;
 
int sumy(int y1, int y2, int Rw, int Cl = 1, int tl = 1, int tr = N) {
   if (y1 > tr || tl > y2) return 0;
   if (y1 <= tl && tr <= y2) return t[Rw][Cl];
   int tm = (tl + tr) >> 1;
   return sumy(y1, y2, Rw, Cl<<1, tl, tm) + sumy(y1, y2, Rw, Cl<<1|1, tm+1, tr);
}
 
int sumx(int x1, int x2, int y1, int y2, int Rw = 1, int tl = 1, int tr = N) {
   if (x1 > tr || tl > x2) return 0;
   if (x1 <= tl && tr <= x2) return sumy(y1, y2, Rw);
   int tm = (tl + tr) >> 1;
   return sumx(x1, x2, y1, y2, Rw<<1, tl, tm) + sumx(x1, x2, y1, y2, Rw<<1|1, tm+1, tr);
}
 
int globalCl;
 
void updatey(int y, int Rw, int Cl = 1, int tl = 1, int tr = N) {
   if (tl == tr) {
      t[Rw][Cl] = 1 - t[Rw][Cl];
      globalCl = Cl;
   } else {
      int tm = (tl + tr) >> 1;
      if (y <= tm)
         updatey(y, Rw, Cl<<1, tl, tm);
      else
         updatey(y, Rw, Cl<<1|1, tm+1, tr);
      t[Rw][Cl] = t[Rw][Cl<<1] + t[Rw][Cl<<1|1];
   }
}
 
void updatex(int x, int y, int Rw = 1, int tl = 1, int tr = N) {
   if (tl == tr) {
      updatey(y, Rw);
   } else {
      int tm = (tl + tr) >> 1;
      if (x <= tm)
         updatex(x, y, Rw<<1, tl, tm);
      else
         updatex(x, y, Rw<<1|1, tm+1, tr);
      for (int k = globalCl; k >= 1; k >>= 1) {
         t[Rw][k] = t[Rw<<1][k] + t[Rw<<1|1][k];
      }
   }
}
 
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
 
   int n, q;
   cin >> n >> q;
 
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         char ch; cin >> ch;
         if (ch == '*')
            updatex(i, j);
      }
   }
 
   while (q--) {
      int t, x1, y1, x2, y2;
      cin >> t >> x1 >> y1;
      if (t == 1) {
         updatex(x1, y1);
      } else {
         cin >> x2 >> y2;
         cout << sumx(x1, x2, y1, y2) << '\n';
      }
   }
 
   return 0;
}