#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.second < rhs.second;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    ll last = -1;
    ll cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (last <= v[i].first) {
            cnt ++;
            last = v[i].second;
        }
    }
    cout << cnt << "\n";
    return 0;
}
