#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 25;
#define mid ((l + r) >> 1)
#define tl (node + 1)
#define tr (node + 2 * (mid - l + 1))
struct SegmentTree {
int arr[MAXN], tree[2 * MAXN];
void build (int l, int r, int node) {
	if (l == r) {
		tree[node] = arr[l];
	} else {
		build(l, mid, tl); build(mid + 1, r, tr);
		tree[node] = min(tree[tl], tree[tr]);
	}
}
int getfirst (int l, int r, int a, int b, int node) {
	if (tree[node] >= a) return 0;
	if (l == r) return l;
	if (tree[tl] >= a) return getfirst(mid + 1, r, a, b, tr);
	if (mid < b) return getfirst(mid + 1, r, a, b, tr);
	int k = getfirst(l, mid, a, b, tl);
	if (k == 0) return getfirst(mid + 1, r, a, b, tr);
	return k;
}
} cur;
int pref[MAXN];
int last[MAXN][19];
vector <int> dp1, dp2;
int n, d, t;
int tt[MAXN];
int cost (int i, int j) {
	int u = i;
	for (int x = 18; x >= 0; x--) {
		if (last[u][x] && last[u][x] <= j) u = last[u][x];
	}
	int x = pref[i] - pref[u];
	x += min(j - u + 1, max(0, t - tt[u] + 1));
	return x;
}
void calc (int l, int r, int opt1, int opt2) {
	if (l > r) return;
	pair <int, int> ll = {1e9, -1};
	for (int j = max(opt1, mid); j <= opt2; j++) {
		ll = min(ll, {cost(mid, j) + dp1[j + 1], j});
	}
	dp2[mid] = ll.first; int opt = ll.second;
	calc(l, mid - 1, opt1, opt);
	calc(mid + 1, r, opt, opt2);
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d >> t;
	for (int i = 1; i <= n; i++) {
		cin >> tt[i];
		cur.arr[i] = tt[i] - i;
	}
	cur.build(1, n, 1);
	for (int i = 1; i <= n; i++) last[i][0] = cur.getfirst(1, n, tt[i] - i, i + 1, 1);
	for (int i = n; i >= 1; i--) {
		if (last[i][0] == 0) {
			pref[i] = min(n - i + 1, max(0, t - tt[i] + 1));
			continue;
		}
		pref[i] = pref[last[i][0]];
		int j = last[i][0] - 1;
		pref[i] += min(j - i + 1, max(0, t - tt[i] + 1));
	}
	for (int j = 1; j <= 18; j++) {
		for (int i = 1; i <= n; i++) {
			last[i][j] = last[last[i][j - 1]][j - 1];
		}
	}
	dp1.resize(n + 1); dp2.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dp1[i] = cost(i, n);
	}
	for (int j = 1; j <= d; j++) {
		calc(1, n, 1, n);
		swap(dp1, dp2);
	}
	cout << dp1[1] << '\n';
}