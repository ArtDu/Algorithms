#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll TABLE_SIZE = 1005;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
 
struct class_cmp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F && lhs.S > rhs.S;
    }
};
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F > rhs.F || lhs.S > rhs.S;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<ll>> val(n, vector<ll>(m + 5, 0));
    for (int x = 1; x <= m; ++x) {
        if(v[0] == 0 || v[0] == x)
            val[0][x] = 1;
    }
 
    for (int k = 1; k < n; ++k) {
        for (int x = 1; x <= m; ++x) {
            if(v[k] == 0 || v[k] == x) {
                val[k][x] += val[k - 1][x - 1];
                val[k][x] %= MOD;
                val[k][x] += val[k - 1][x + 1];
                val[k][x] %= MOD;
                val[k][x] += val[k - 1][x];
                val[k][x] %= MOD;
            }
        }
    }
    ll c = 0;
    for (int x = 1; x <= m; ++x) {
        c += val[n - 1][x];
        c %= MOD;
    }
    cout << c << "\n";
    return 0;
}
