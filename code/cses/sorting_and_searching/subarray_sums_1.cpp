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
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll cur = v[0];
    ll l = 0;
    ll r = 1;
    ll ans = 0;
    while(r < n) {
        if(cur == x) {
            ans++;
            cur -= v[l];
            cur += v[r];
            l++; r++;
        } else if(cur > x) {
            cur -= v[l];
            l++;
        } else {
            cur += v[r];
            r++;
        }
    }
    while(l < n) {
        if(cur == x) {
            ans++;
            break;
        } else if(cur > x) {
            cur -= v[l];
            l++;
        } else {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
