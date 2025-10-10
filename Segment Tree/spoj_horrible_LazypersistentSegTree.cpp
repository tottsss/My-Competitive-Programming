#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll value;
    ll lazy;
    node *l, *r;
    node() {
        value = lazy = 0;
        l = r = NULL;
    }
};

void lazy(node *&t, ll l, ll r) {
    if (t->lazy != 0) {
        t->value += t->lazy * (r - l + 1);
        // if t is not a leaf
        if (l < r) {
            if (t->l == NULL) t->l = new node();
            if (t->r == NULL) t->r = new node();
            t->l->lazy += t->lazy;
            t->r->lazy += t->lazy;
        }
        t->lazy = 0;
    }
}

void update(node *&t, ll l, ll r, int x, int y, ll v) {
    // if t == NULL then t hasn't been visited and hasn't been passed any lazy value
    if (t == NULL) t = new node();
    else lazy(t, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        t->value += v * (r - l + 1);
        if (l < r) {
            if (t->l == NULL) t->l = new node();
            if (t->r == NULL) t->r = new node();
            t->l->lazy += v;
            t->r->lazy += v;
        }
        return;
    }
    int m = (l + r) >> 1;
    update(t->l, l, m, x, y, v);
    update(t->r, m + 1, r, x, y, v);
    t->value = t->l->value + t->r->value;
}

ll get(node *t, int l, int r, int x, int y) {
    if (t == NULL) return 0;
    lazy(t, l, r);
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return t->value;
    int m = (l + r) >> 1;
    return get(t->l, l, m, x, y) + get(t->r, m + 1, r, x, y);
}

// free memory
void del(node *&t) {
    if (t == NULL) return;
    del(t->l);
    del(t->r);
    delete t;
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        node *t = NULL;
        int n, c;
        scanf("%d %d", &n, &c);
        while (c--) {
            int i;
            scanf("%d", &i);
            if (i == 0) {
                int p, q, v;
                scanf("%d %d %d", &p, &q, &v);
                update(t, 1, n, p, q, v);
            } else {
                int p, q;
                scanf("%d %d", &p, &q);
                printf("%lld\n", get(t, 1, n, p, q));
            }
        }
        del(t);
    }
}