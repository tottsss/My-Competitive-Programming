#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair

const ll maxn = 1e6 + 1, maxm = 3e5 + 1,  maxk = 61;
const ll inf = 1000000000, mod = inf + 7, mod2 = 998244353;
const ll pa = 31, block = 400;

using namespace std;

int n, m, q, cl;
int up[21][maxn], tin[maxn], tout[maxn], parent[maxn];
vector<int> g[maxn], z[maxn];
struct node{
    int sum;
    node *l, *r;
    node (int new_sum = 0){
        l = r = nullptr;
        sum = new_sum;
    }
    node (node *tl, node *tr){
        l = tl, r = tr;
        sum = 0;
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
    node (node *v){
        sum = v->sum;
        l = v->l;
        r = v->r;
    }
} *t[maxn];
node* build(int tl = 1, int tr = m){
    if (tl == tr){
        return new node(0);
    }
    int tm = (tl + tr) / 2;
    return new node(build(tl, tm), build(tm + 1, tr));
}
node* upd(node *v, int pos, int tl = 1, int tr = m){
    if (tl == tr)
        return new node(1);
    int tm = (tl + tr) / 2;
    node *cur = new node(v);
    if (pos <= tm){
        cur->l = upd(v->l, pos, tl, tm);
    }
    else{
        cur->r = upd(v->r, pos, tm + 1, tr);
    }
    cur->sum = cur->l->sum + cur->r->sum;
    //cout << cur->sum << " " << tl << " " << tr << '\n';
    return cur;
}
int get(int k, node *v, node *v2, node *v3, node *v4, int tl = 1, int tr = m){
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    int sum = v->l->sum + v2->l->sum - v3->l->sum - v4->l->sum;
  //  cout << tl << " " << tr << " " << sum << '\n';
    if (sum < k){
        return get(k - sum, v->r, v2->r, v3->r, v4->r, tm + 1, tr);
    }
    else{
        return get(k, v->l, v2->l, v3->l, v4->l, tl, tm);
    }
}
void dfs(int v = 1, int p = 0){
    up[0][v] = p;
    t[v] = t[p];
    tin[v] = ++cl;
    parent[v] = p;
    for (int i = 1; i <= 20; ++i){
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for (auto it : z[v]){
        t[v] = upd(t[v], it);
    }
   // cout << t[v]->sum << '\n';
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
        }
    }
    tout[v] = ++cl;
}
bool upper(int a, int b){
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
int lca(int a, int b){
    if (upper(a, b))
        return a;
    if (upper(b, a))
        return b;
    for (int i = 20; i >= 0; --i){
        if (up[i][a] > 0 && !upper(up[i][a], b)){
            a = up[i][a];
        }
    }
    return up[0][a];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= m; ++i){
        int c;
        cin >> c;
        z[c].pb(i);
    }
    t[0] = build();
    dfs();
    for (int i = 1; i <= q; ++i){
        int u, v, a;
        cin >> u >> v >> a;
        int lc = lca(u, v);
        int x = min(a, t[v]->sum + t[u]->sum - t[lc]->sum - t[parent[lc]]->sum);
        cout << x << " ";
        for (int i = 1; i <= x; ++i){
            int y = get(i, t[v], t[u], t[lc], t[parent[lc]]);
            cout << y << " ";
        }
        cout << '\n';
    }
}

