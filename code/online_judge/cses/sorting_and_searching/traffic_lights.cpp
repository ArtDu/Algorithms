#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e15;
 
struct classcomp {
    bool operator()(const pair<ll, ll> &lhs, const pair<ll, ll> &rhs) const {
        return abs(lhs.first - lhs.second) < abs(rhs.first - rhs.second);
    }
};
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll x, n, p;
    cin >> x >> n;
    set<ll> increasing;
    set<ll, greater<>> decreasing;
    multiset<pair<ll, ll>, classcomp> m;
 
    increasing.insert(x);
    increasing.insert(0);
    decreasing.insert(x);
    decreasing.insert(0);
    m.insert({0, x});
    for (int i = 0; i < n; ++i) {
        cin >> p;
 
        ll left = *(decreasing.upper_bound(p));
        ll right = *(increasing.upper_bound(p));
        decreasing.insert(p);
        increasing.insert(p);
 
        auto it = m.find({left, right});
        m.erase(it);
        m.insert({left, p});
        m.insert({p, right});
 
        pair<ll, ll> pr = *(m.rbegin());
        ll mx = pr.second - pr.first;
 
 
        cout << mx << " ";
 
    }
    return 0;
}
