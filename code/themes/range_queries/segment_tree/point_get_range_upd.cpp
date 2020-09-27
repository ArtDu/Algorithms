//https://cses.fi/problemset/task/1651/
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define P pair
#define MAXX 1e15

using ll = long long;

ll n, q;
vec<ll> tree;
vec<ll> v;

void add(ll k, ll x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

void upd_range(ll a, ll b, ll u) {
    add(a, u);
    if(b + 1 < n)
        add(b + 1, -u);
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

    v.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    ll i = 1;
    while (i <= n) {
        i *= 2;
    }
    n = i;

    tree.resize(2*n + 5);
    for (i = 1; i < v.size(); ++i) {
        ll diff = v[i] - v[i - 1];
        add(i - 1, diff);
    }

    ll op, a, b, u;
    for (i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> u;
            --a; --b;
            upd_range(a, b, u);
        } else {
            cin >> a;
            --a;
            cout << sum(0, a) << "\n";
        }
    }
    return 0;
}