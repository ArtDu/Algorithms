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
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<P<ll,ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F >> v[i].S;
    }
    sort(v.begin(), v.end());
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cur += v[i].F;
        ans += v[i].S - cur;
    }
    cout << ans << "\n";
    return 0;
}
 
