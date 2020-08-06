//https://cses.fi/problemset/task/1646/
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

ll n, q, a, b;
vec<ll> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    p.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << p[b] - p[a - 1] << "\n";
    }


    return 0;
}