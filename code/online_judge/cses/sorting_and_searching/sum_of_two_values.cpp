#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.first < rhs.first;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n >> x;
    // <val, pos>
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmp);
    ll l = 0, r = v.size() - 1, y;
    while (l < r) {
        y = x - v[r].first;
        while (l < r && v[l].first < y) {
            l++;
        }
        if (l >= r) {
            break;
        }
        if (v[l].first == y) {
            cout << v[l].second + 1 << " " << v[r].second + 1 << "\n";
            return 0;
        }
        r--;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
