#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
#define F first
#define S second
 
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F < rhs.F;
}
 
vector<pair<ll, ll>> v;
 
pair<ll, ll> find_sum_of_two(ll l, ll r, ll x) {
    ll y;
    while (l < r) {
        y = x - v[r].F;
        while (l < r && v[l].F < y) {
            l++;
        }
        if (l >= r) {
            break;
        }
        if (v[l].F == y) {
            return {v[l].second, v[r].second};
        }
        r--;
    }
    return {-1, -1};
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n >> x;
    // <val, pos>
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmp);
 
 
    for (int l = 0; l < n; ++l) {
        for (int r = l + 3; r < n; ++r) {
            ll y = x - v[l].F - v[r].F;
            auto pr = find_sum_of_two(l + 1, r - 1, y);
            if (pr.F != -1) {
                cout << v[l].S + 1 << " "
                     << pr.F + 1 << " "
                     << pr.S + 1 << " "
                     << v[r].S + 1 << " ";
                return 0;
            }
        }
    }
 
 
    cout << "IMPOSSIBLE\n";
    return 0;
}
