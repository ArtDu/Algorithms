#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld PI = cosl(-1.0);

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

ld scalmul(Vec v1, Vec v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

ld vectmul(Vec v1, Vec v2) {
    return (v1.x * v2.y - v1.y * v2.x);
}

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    Vec v1, v2;
    cin >> v1.x >> v1.y >> v2.x >> v2.y;
    ld res = atan2l(vectmul(v1, v2), scalmul(v1, v2));

    cout << fabsl(res) << "\n";
    return 0;
}
