// https://cses.fi/problemset/task/1750/

/*
 * Find where we will come after k steps start from x node.
 * */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MAXX = 2e5 + 5;
const ll LG = 35;
const ll MOD = 1e9 + 7;

#define P pair
#define F first
#define S second
#define vec vector

ll n, q;
vec<vec<ll>> succ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    // succ[Count Of steps][Node] = to Node
    succ.resize(LG, vec<ll>(MAXX));

    for (int i = 1; i <= n; ++i) {
        cin >> succ[0][i];
    }

    for (ll i = 1; i < LG; ++i) {
        for (int j = 1; j <= n; ++j) {
            succ[i][j] = succ[i - 1][succ[i - 1][j]];
        }
    }

    ll x, k;
    while(q--){
        cin >> x >> k;
        for(ll j = 0; j < LG; ++j) {
            if((1LL << j) & k)
                x = succ[j][x];
        }
        cout << x << "\n";
    }

    return 0;
}

