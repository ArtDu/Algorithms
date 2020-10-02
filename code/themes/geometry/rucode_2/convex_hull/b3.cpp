#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct point2d {
    long long x, y;
};

struct vector2d {
    long long x, y;

    long long len() {
        return x * x + y * y;
    }

    vector2d(point2d a, point2d b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

long long cross(vector2d a, vector2d b) {
    return a.x * b.y - b.x * a.y;
}

vector<point2d> get_convex_hull(vector<point2d> points) {
    /* First phase */

    for (int i = 1; i < points.size(); ++i) {
        if (points[i].x < points[0].x
            || (points[i].x == points[0].x && points[i].y < points[0].y))
        {
            swap(points[i], points[0]);
        }
    }

    sort(
            points.begin() + 1,
            points.end(),
            [&points](point2d a, point2d b) {
                auto v1 = vector2d(points[0], a);
                auto v2 = vector2d(points[0], b);
                return cross(v1, v2) > 0 || (cross(v1, v2) == 0 && v1.len() < v2.len());
            }
    );

    /* Second phase */

    vector<point2d> ch = {points[0], points[1]};

    for (int i = 2; i < points.size(); ++i) {
        while (ch.size() >= 2
               && cross(
                vector2d(ch[ch.size() - 2], ch[ch.size() - 1]),
                vector2d(ch[ch.size() - 1], points[i])
        ) <= 0)
        {
            ch.pop_back();
        }

        ch.push_back(points[i]);
    }

    return ch;
}

int main() {
    int n;
    cin >> n;
    vector<point2d> points(n);

    for (auto& pt : points) {
        cin >> pt.x >> pt.y;
    }

    auto ch = get_convex_hull(points);

    cout << ch.size() << endl;

    for (auto pt : ch) {
        cout << pt.x << ' ' << pt.y << endl;
    }

    return 0;
}
