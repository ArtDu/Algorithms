#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
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
 
vector<ll> items;
vector<ll> val(MAXX + 5);
 
ll solve(ll sum) {
    val[0] = 0;
 
    for (int x = 1; x <= sum; ++x) {
        ll mn = MAXX + 5;
        for (int k = 0; k < items.size(); ++k) {
            if (x - items[k] >= 0) {
                mn = min(mn, val[x - items[k]] + 1);
            }
        }
        val[x] = mn;
    }
    return (val[sum] == 0 || val[sum] >= MAXX + 5) ? -1 : val[sum];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n >> x;
    items.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }
    cout << solve(x) << "\n";
 
    return 0;
}
