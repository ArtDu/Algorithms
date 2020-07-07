#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
#define F first
#define S second
 
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.first < rhs.first;
}
 
vector<pair<ll,ll>> v;
 
pair<ll,ll> find_sum_of_two(ll r, ll x) {
    ll y, l = 0;
    while (l < r) {
        y = x - v[r].first;
        while (l < r && v[l].first < y) {
            l++;
        }
        if (l >= r) {
            break;
        }
        if (v[l].first == y) {
            return {v[l].second + 1,v[r].second + 1};
        }
        r--;
    }
    return {-1,-1};
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
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmp);
 
    ll y;
    for (int i = 2; i < n; ++i) {
        y = x - v[i].F;
        auto pr = find_sum_of_two(i - 1, y);
        if(pr.F != -1) {
            cout << pr.F << " " << pr.S << " " << v[i].S + 1 << "\n";
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE\n";
    return 0;
}
