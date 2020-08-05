//https://cses.fi/problemset/task/1647
//minimum in segment
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
vec<vec<ll>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    st.resize(LG, vec<ll>(n + 5));
    for (int i = 1; i <= n; ++i) {
        cin >> st[0][i];
    }

    vec<ll> log(MAXX);
    log[1] = 0;
    for (int i = 2; i < MAXX; ++i) {
        log[i] = log[i / 2] + 1;
    }

    ll sz = 0;
    for (int i = 1; i < LG; ++i) {
        sz = 1LL << (i - 1);
        for (int j = 1; j + sz <= n; ++j) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + sz]);
        }
    }

    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        sz = b - a + 1;
        sz = log[sz];
        cout << min(st[sz][a], st[sz][b - (1 << sz) + 1]) << "\n";
    }



    return 0;
}

