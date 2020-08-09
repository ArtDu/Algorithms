//https://cses.fi/problemset/task/1648/
//sum of range
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define P pair
#define MAXX 1e15

using ll = long long;

ll n, q;
vec<ll> tree;

void upd(ll k, ll x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

ll sum(ll a, ll b) {
    ll s = 0;

    a += n;
    b += n;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {


    cin >> n >> q;

    vec<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll i = 1;
    while (i < n) {
        i *= 2;
    }
    n = i;


    tree.resize(2 * n + 5);
    for (i = 0; i < v.size(); ++i) {
        upd(i, v[i]);
    }

    ll op, a, b, x;
    for (i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> a >> x;
            a--;
            upd(a, x);
        } else {
            cin >> a >> b;
            a--;
            b--;
            cout << sum(a, b) << "\n";
        }
    }
    return 0;
}
