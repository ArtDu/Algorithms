//https://cses.fi/problemset/task/1739/
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define P pair
#define F first
#define S second
#define MAXX 1e15

using ll = long long;

ll n, q;
vec<vec<ll>> v;
vec<vec<ll>> tree;

ll p(ll k){
    return k & -k;
}

void add(ll y, ll x, ll val){
    for (int i = y; i <= n; i += p(i)) {
        for (int j = x; j <= n; j += p(j)) {
            tree[i][j] += val;
        }
    }
}

ll sum(ll y, ll x){
    ll s = 0;

    for(ll i = y; i >= 1; i -= p(i)){
        for (int j = x; j >= 1; j -= p(j)) {
            s += tree[i][j];
        }
    }

    return s;
}

ll sum(ll y1, ll x1, ll y2, ll x2){
    ll dy = y1 - 1, dx = x1 - 1;
    ll by = y2, bx = x1 - 1;
    ll cy = y1 - 1, cx = x2;
    ll ay = y2, ax = x2;
    return sum(ay, ax) - sum(cy, cx) - sum(by, bx) + sum(dy, dx);
}

void upd(ll y, ll x){
    ll diff = !v[y][x] - v[y][x];
    v[y][x] = !v[y][x];
    add(y, x, diff);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    v.resize(n + 5, vec<ll>(n + 5));
    tree.resize(n + 5, vec<ll>(n + 5));
    char x;
    for (ll i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if(x == '*'){
                v[i][j] = 1;
                add(i, j, v[i][j]);
            }
        }
    }

    ll op, y1, x1, y2, x2;
    for (ll i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> y1 >> x1;
            upd(y1, x1);
        } else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y1, x1, y2, x2) << "\n";
        }
    }
    return 0;
}
