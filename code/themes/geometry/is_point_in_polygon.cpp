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

ld square(Vec v1, Vec v2) {
    return fabsl(vectmul(v1, v2) / 2);
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

    int n;
    cin >> n;
    Vec p1, p2;
    cin >> p1.x >> p1.y;
    p2.x = XMAX + 3;
    p2.y = p1.y + 1;

    vector<Vec> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }

    
    for (int i = 1; i < v.size(); ++i) {
        if(isOnSegment(p1, v[i - 1], v[i])) {
            cout << "YES\n";
            return 0;
        }
    }
    if(isOnSegment(p1, v[0], v[v.size() - 1])) {
        cout << "YES\n";
        return 0;
    }


    int cnt = 0;
    for (int i = 1; i < v.size(); ++i) {
        cnt += areSegmentsIntersecting(p1, p2, v[i - 1], v[i]);
    }
    cnt += areSegmentsIntersecting(p1, p2, v[0], v[v.size() - 1]);
    
    cout << (cnt % 2 == 1 ? "YES" : "NO") << "\n";
    return 0;
}