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
    vector<vector<ll>> val(n + 5, vector<ll>(m + 5));
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            if(w != h) {
                ll mn = MAXX;
                for (int k = 1; k < w; ++k) {
                    mn = min(mn, val[h][k] + val[h][w - k] + 1);
                }
                for (int k = 1; k < h; ++k) {
                    mn = min(mn, val[k][w] + val[h - k][w] + 1);
                }
                val[h][w] = mn;
            }
        }
    }
    cout << val[n][m] << "\n";
    return 0;
}
