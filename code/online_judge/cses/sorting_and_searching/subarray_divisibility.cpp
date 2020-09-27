#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
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
 
    ll n, x;
    cin >> n;
    vector<ll> v(n);
    vector<ll> pref(n + 1);
    vector<vector<ll>> m(n);
    m[0].push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pref[i + 1] = (pref[i] + v[i]) % n;
        if(pref[i + 1] < 0) 
            pref[i + 1] += n; //real mod
        m[pref[i + 1]].push_back(i + 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll y = (pref[i] - n) % n;
        if(y < 0)
            y += n;
        ans += lower_bound(m[y].begin(), m[y].end(), i) - m[y].begin();
    }
    cout << ans << "\n";
 
    return 0;
}
