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
    vector<ll> v(n);
    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }
    if(mx >= sum - mx) {
        cout << mx * 2 << "\n";
        return 0;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll l, r;
    for(l = 0, r = v.size() - 1; l < r;) {
        if(v[l] == v[r]) {
            ans += v[l];
            l++; r--;
        } else if(v[l] < v[r]) {
            ans += v[l];
            v[r] -= v[l];
            l++;
        } else {
            ans += v[r];
            v[l] -= v[r];
            r--;
        }
    }
    ans *= 2;
    if(l == r) {
        ans += v[l];
    }
    cout << ans << "\n";
    return 0;
}
