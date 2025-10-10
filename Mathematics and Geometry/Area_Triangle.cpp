#include <bits/stdc++.h>
using i64 = long long;

struct Point {
    double x, y;
    Point(double _ = 0, double __ = 0) : x(_), y(__) {}
} P[3];

double get(int i, int j) {
    return sqrt((P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y));
}

int main() {
    for (int i = 0; i < 3; i++) {
        std::cin >> P[i].x >> P[i].y;
    }
    double a = get(0, 1), b = get(0, 2), c = get(1, 2);
    double p = (a + b + c) / 2;
    double ans = sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << std::fixed << std::setprecision(4);
    std::cout << ans << "\n";
    return 0;
}
// https://atcoder.jp/contests/abc002/tasks/abc002_3