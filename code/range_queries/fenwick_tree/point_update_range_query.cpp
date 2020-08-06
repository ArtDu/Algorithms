//https://cses.fi/problemset/task/1648
#include <bits/stdc++.h>
 
using namespace std;
 
#define vec vector
#define P pair
#define MAXX 1e15
 
using ll = long long;
 
ll n, q;
vec<ll> v;
vec<ll> tree;
 
ll p(ll k) {
    return k & -k;
}
 
ll sum(ll k) {
    ll s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= p(k);
    }
    return s;
}
 
ll sum(ll a, ll b) {
    return sum(b) - sum(a - 1);
}
 
void add(ll k, ll x) {
    while (k <= n) {
        tree[k] += x;
        k += p(k);
    }
}
 
void update(ll k, ll x) {
    ll diff = x - v[k];
    v[k] = x;
    add(k, diff);
}
 
int main() {
 
 
    cin >> n >> q;
 
    tree.resize(n + 5);
    v.resize(n + 5);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        add(i, v[i]);
    }
    ll op, a, b;
    for (ll i = 0; i < q; ++i) {
        cin >> op >> a >> b;
        if (op == 1) {
            update(a, b);
        } else {
            cout << sum(a, b) << "\n";
        }
    }
    return 0;
}
