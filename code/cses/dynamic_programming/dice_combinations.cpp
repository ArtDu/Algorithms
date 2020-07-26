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
 
ll solve(ll n) {
 
    val[0] = 1; // base case
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if(i - j >= 0) {
                val[i] += val[i - j];
                val[i] %= MOD;
            }
        }
    }
    return val[n];
 
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
