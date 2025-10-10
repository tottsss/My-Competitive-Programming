#include <bits/stdc++.h>

using i64 = long long;

constexpr int alphabet = 256;
std::vector<int> sort_cyclic_shifts(const std::string &s) {
    int n = s.length();
    std::vector<int> p(n), c(n), cnt(std::max(n, alphabet), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    std::vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        std::fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            std::pair<int, int> cur{c[p[i]], c[(p[i] + (1 << h)) % n]};
            std::pair<int, int> prev{c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

std::vector<int> suffix_array(std::string s) {
    s += "$";
    std::vector<int> shifts = sort_cyclic_shifts(s);
    shifts.erase(shifts.begin());
    return shifts;
}

struct Hash {
    static constexpr int P = 1000000007, M = 29;
    int n;
    std::vector<int> a, pw;
    Hash(std::string s) : n(s.size()), a(n + 1), pw(n + 1, 1) {
        for (int i = 1; i <= n; i++)
            pw[i] = 1LL * pw[i - 1] * M % P;
        for (int i = 0; i < n; i++)
            a[i + 1] = (1LL * a[i] * M + (s[i] - 'a' + 1)) % P;
    }
    int get(int l, int r) {
        int res = a[r] - 1LL * pw[r - l] * a[l] % P;
        if (res < 0)
            res += P;
        return res;
    }
};

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::string s, t;
    std::cin >> s >> t;
    std::swap(s, t);
    
    auto SuffixArray = suffix_array(s + s + t + t);
    
    std::vector<int> p;
    for (int x : SuffixArray) {
        if (x < n || (2 * n <= x && x < 3 * n)) {
            p.push_back(x);
        }
    }
    
    Hash S(s + s), T(t + t);
    
    Fenwick<int> f(2 * n);
    
    i64 ans = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        int x = p[i];
        if (x < n) {
            f.add(i, 1);
        } else {
            x -= 2 * n;
            int lo = 0, hi = i;
            while (lo < hi) {
                int m = (lo + hi) / 2;
                int k = p[m];
                int hashValue = -1;
                if (k < n) {
                    hashValue = S.get(k, k + n);
                } else {
                    k -= 2 * n;
                    hashValue = T.get(k, k + n);
                }
                if (hashValue == T.get(x, x + n)) {
                    hi = m;
                } else {
                    lo = m + 1;
                }
            }
            ans += f.sum(lo);
        }
    }
    
    ans = n * 1LL * n - ans;
    
    std::cout << ans << "\n";
    
    return 0;
}
