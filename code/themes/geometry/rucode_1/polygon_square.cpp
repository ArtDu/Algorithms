#include <bits/stdc++.h>

/*

test:

5
2 4
5 5
7 3
4 1
4 3

ans:
17/2
*/

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
    return (v1.x * v2.y - v2.x * v1.y);
}


int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    Vec p1, p2, pfst;

    cin >> p1.x >> p1.y;
    pfst = p1;
    ld s = 0;

    //gauss's formula for polygon square
    for (int i = 1; i < n; ++i) {
        cin >> p2.x >> p2.y;
        s += vectmul(p1, p2);
        p1 = p2;
    }
    s += vectmul(p2, pfst);
    cout << fabsl(s) / (long double) 2 << "\n";
    return 0;
}
