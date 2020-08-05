// https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 2e5 + 5;
const ll LG = 20;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
#define pb push_back
#define vec vector
 
ll n, q, yy1, xx1, yy2, xx2;
ll dy, dx, cy, cx, by, bx, ay, ax;
char x;
vec<vec<ll>> p;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
    p.resize(n + 5, vec<ll>(n + 5));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            if(x == '*'){
                p[i][j]++;
            }
        }
    }
 
    for (int i = 0; i < q; ++i) {
        cin >> yy1 >> xx1 >> yy2 >> xx2;
        dy = yy1 - 1; dx = xx1 - 1;
        cy = yy1 - 1; cx = xx2;
        by = yy2; bx = xx1 - 1;
        ay = yy2; ax = xx2;
 
        cout << p[ay][ax] - p[cy][cx] - p[by][bx] + p[dy][dx] << "\n";
    }
 
 
 
    return 0;
}
