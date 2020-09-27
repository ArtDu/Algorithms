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
 
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> val(n, vector<ll>(n));
    vector<ll> p(n + 5);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        p[i + 1] = p[i] + v[i];
        val[i][i] = v[i];
    }
 
    for (int sz = 1; sz < n; ++sz) {
        for (ll l = 0, r = sz; r < n; l++, r++) {
            ll remove_left = (p[r + 1] - p[l + 1] - val[l + 1][r]) + v[l];
            ll remove_right = (p[r] - p[l] - val[l][r - 1]) + v[r];
            val[l][r] = max(remove_left, remove_right);
        }
    }
    cout << val[0][n - 1] << "\n";
    return 0;
}
