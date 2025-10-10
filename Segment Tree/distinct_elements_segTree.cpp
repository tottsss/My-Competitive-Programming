#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LB lower_bound
#define UB upper_bound
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vii vector<ii>
#define vvii vector<vii>
#define vll vector<ll>
#define vld vector<ld>
 
const int N = 1 << 20, inf = 2e9;
 
int n, q;
vi v;
vi seg[N];
 
void build(int p = 1, int l = 0, int r = n-1) {
    if (l > r) return;
    if (l == r) {
        seg[p] = {v[l]};
        return;
    }
    int mid = (l+r)/2;
    build(p*2, l, mid);
    build(p*2+1, mid+1, r);
    seg[p].resize(seg[p*2].size() + seg[p*2+1].size());
    merge(all(seg[p*2]), all(seg[p*2+1]), seg[p].begin());
}
int query(int a, int b, int p = 1, int l = 0, int r = n-1) {
    if (l > r || a > r || b < l) return 0;
    if (a <= l && r <= b) {
        return (r-l+1) - (UB(all(seg[p]), b) - seg[p].begin());
    }
    int mid = (l+r)/2;
    int x = query(a, b, p*2, l, mid);
    int y = query(a, b, p*2+1, mid+1, r);
    return x + y;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    v.resize(n);
    for (int &i : v) cin >> i;
    map<int, int> last;
    for (int i = n-1; i >= 0; i--) {
      if (!last.count(v[i])) {
        last[v[i]] = i;
        v[i] = inf;
      }else {
        int x = last[v[i]];
        last[v[i]] = i;
        v[i] = x;
      }
    }
    build();
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--; r--;
      // cuantos elementos hay > r en el rango [l, r]
      cout << query(l, r) << "\n";
    }
    return 0;
}