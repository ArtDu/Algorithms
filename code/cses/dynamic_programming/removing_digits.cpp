#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll MOD = 1e9 + 7;
 
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
 
vector<ll> val(MAXX + 5);
 
ll solve(ll num) {
    if(num == 0) return 0;
    if(num < 0) return MAXX + 5;
    if(val[num] != 0) return val[num];
 
    ll tmp = num;
    ll mn = MAXX + 5;
    while(tmp) {
        ll rem = (tmp % 10);
        if(rem != 0)
            mn = min(mn, solve(num - rem) + 1);
        tmp /= 10;
    }
    val[num] = mn;
    return val[num];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    cout << solve(n) << "\n";
 
    return 0;
}
