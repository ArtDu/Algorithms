#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define PB push_back
#define P pair
#define F first
#define S second
#define IN 1
#define OUT 0
 
 
const ll MAXX = 1e15;
 
struct classcomp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F;
    }
};
 
bool cmp(P<ll, P<ll, ll>> &lhs, P<ll, P<ll, ll>> &rhs) {
    return lhs.S.S < rhs.S.S;
}
 
 
ll search(vector<ll> &v, ll mx_sec, ll counts) {
    ll l = 0, r = counts * mx_sec + 1, m, curr, ans;
    while (l <= r) {
        m = (r + l) / 2;
        curr = 0;
        for (auto &sec_per_item : v) {
            if(curr >= counts) {
                break;
            }
            curr += m / sec_per_item;
        }
        if(curr >= counts) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    cout << search(v, mx, t) << "\n";
    return 0;
}
