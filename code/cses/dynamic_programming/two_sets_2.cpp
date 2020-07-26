#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll TABLE_SIZE = 1005;
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
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    ll sum = (n + 1) * n / 2;
 
    if (sum % 2 != 0) {
        cout << "0\n";
        return 0;
    }
    sum /= 2;
 
    vector<vector<ll>> val(n, vector<ll>(sum + 1));
    val[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            val[i][j] = val[i - 1][j];
            ll left = j - i;
            if(left >= 0) {
                (val[i][j] += val[i - 1][left]) %= MOD;
            }
        }
    }
    cout << val[n - 1][sum];
    return 0;
}
