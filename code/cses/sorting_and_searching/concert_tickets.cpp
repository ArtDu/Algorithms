#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m, x;
    cin >> n >> m;
    multiset<ll, greater<ll>> h;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        h.insert(x);
    }
 
    ll t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        auto it = h.lower_bound(t);
        if (it == h.end()) {
            cout << "-1\n";
        } else {
            cout << *it << "\n";
            h.erase(it);
        }
    }
 
    return 0;
}
