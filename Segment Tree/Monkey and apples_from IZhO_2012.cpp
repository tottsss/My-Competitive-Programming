#include <map>
#include <set>
#include <new>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <locale>
#include <memory>
#include <vector>
#include <cstdio>
#include <limits>
#include <cassert>
#include <ctype.h>
#include <climits>
#include <cstdarg>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <complex>
#include <iterator>
#include <iostream>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>
 
#define name "f"
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define sz(s) ((int) s.size ())
#define all(s) s.begin (), s.end ()
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
const int N = 123456;
const double eps = 1e-11;
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;
 
struct tree {
    int sum, add, tl, tr, l, r;
    tree () : sum (0), add (0), l (-1), r (-1) {}
};
 
int cnt = 2;
tree t[64 * N];
 
void push (int v) {
    if (t[v].add) {
        t[v].sum = t[v].tr - t[v].tl + 1;
        int tm = (t[v].tl + t[v].tr) >> 1;
        if (t[v].l == -1) {
            t[v].l = cnt++;
            t[t[v].l].tl = t[v].tl;
            t[t[v].l].tr = tm;
        }
        if (t[v].r == -1) {
            t[v].r = cnt++;
            t[t[v].r].tl = tm + 1;
            t[t[v].r].tr = t[v].tr;
        }
        t[t[v].l].add = t[t[v].r].add = 1;
        t[v].add = 0;
    }
}
 
void update (int v, int l, int r) {
    push (v);
    if (l == t[v].tl && r == t[v].tr) {
        t[v].add = 1;
        push (v);
    } else {
        int tm = (t[v].tl + t[v].tr) >> 1;
        if (t[v].l == -1) {
            t[v].l = cnt++;
            t[t[v].l].tl = t[v].tl;
            t[t[v].l].tr = tm;
        }
        if (t[v].r == -1) {
            t[v].r = cnt++;
            t[t[v].r].tl = tm + 1;
            t[t[v].r].tr = t[v].tr;
        }
        if (l > tm) {
            update (t[v].r, l, r);
        } else if (r <= tm) {
            update (t[v].l, l, r);
        } else {
            update (t[v].l, l, tm);
            update (t[v].r, tm + 1, r);
        }
        push (t[v].l);
        push (t[v].r);
        t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
    }
}
 
int get (int v, int l, int r) {
    push (v);
    if (l == t[v].tl && r == t[v].tr) {
        return t[v].sum;
    } else {
        int tm = (t[v].tl + t[v].tr) >> 1;
        if (t[v].l == -1) {
            t[v].l = cnt++;
            t[t[v].l].tl = t[v].tl;
            t[t[v].l].tr = tm;
        }
        if (t[v].r == -1) {
            t[v].r = cnt++;
            t[t[v].r].tl = tm + 1;
            t[t[v].r].tr = t[v].tr;
        }
        if (l > tm) {
            return get (t[v].r, l, r);
        } else if (r <= tm) {
            return get (t[v].l, l, r);
        } else {
            return get (t[v].l, l, tm) + get (t[v].r, tm + 1, r);
        }
    }
}
 
int main()
{
    freopen (name".in", "r", stdin);
    freopen (name".out", "w", stdout);
    int q;
    scanf ("%d", &q);
    t[1].sum = 0; t[1].add = 0;
    t[1].tl = 1; t[1].tr = inf;
    int c = 0;
    while (q--) {
        int d, x, y;
        scanf ("%d %d %d", &d, &x, &y);
        if (d == 1) {
            printf ("%d\n", c = get (1, x + c, y + c));
        } else {
            update (1, x + c, y + c);
        }
    }
    return 0;
}