#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld PI = cosl(-1.0);
const ld XMAX = 1e4;

struct Vec {
    ld x, y;

    ld len() const {
        return hypotl(x, y);
    }
};

Vec operator+(Vec v1, Vec v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vec operator-(Vec v1, Vec v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vec operator*(Vec v, ld a) {
    return {v.x * a, v.y * a};
}

Vec operator*(ld a, Vec v) {
    return {v.x * a, v.y * a};
}

Vec operator/(Vec v, ld a) {
    return {v.x / a, v.y / a};
}

ld dist(Vec v1, Vec v2) {
    return (v2 - v1).len();
}

ld scalmul(Vec v1, Vec v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

ld vectmul(Vec v1, Vec v2) {
    return (v1.x * v2.y - v1.y * v2.x);
}

bool areParallell(Vec v1, Vec v2) {
    return (vectmul(v1, v2) == 0);
}

int sign(ld x) {
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    }
    return -1;
}

bool isOnSegment(Vec p, Vec p1, Vec p2) {
    return vectmul(p - p1, p2 - p1) == 0 && scalmul(p1 - p, p2 - p) <= 0;
}

bool areSegmentsIntersecting(Vec p1, Vec p2, Vec p3, Vec p4) {
    if (areParallell(p2 - p1, p4 - p3)) {
        return isOnSegment(p1, p3, p4) || isOnSegment(p2, p3, p4) ||
               isOnSegment(p3, p1, p2) || isOnSegment(p4, p1, p2);
    } else {
        return sign(vectmul(p2 - p1, p4 - p1)) * sign(vectmul(p2 - p1, p3 - p1)) <= 0 &&
               sign(vectmul(p4 - p3, p1 - p3)) * sign(vectmul(p4 - p3, p2 - p3)) <= 0;
    }
}

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    Vec t1, t2, t3, p1, p2;
    cin >> t1.x >> t1.y >> t2.x >> t2.y >> t3.x >> t3.y;
    cin >> p1.x >> p1.y;
    p2.x = XMAX + 1;
    p2.y = p1.y + 1;

    if (isOnSegment(p1, t1, t2) || isOnSegment(p1, t2, t3) || isOnSegment(p1, t3, t1)) {
        cout << "In\n";
        return 0;
    }

    int cnt = 0;
    cnt += areSegmentsIntersecting(p1, p2, t1, t2);
    cnt += areSegmentsIntersecting(p1, p2, t2, t3);
    cnt += areSegmentsIntersecting(p1, p2, t3, t1);
    cout << (cnt == 1 ? "In" : "Out") << "\n";
    return 0;
}