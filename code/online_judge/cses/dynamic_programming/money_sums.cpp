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
    vector<ll> v(n + 5);
    ll mx_sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        mx_sum += v[i];
    }
    vector<vector<char>> val(n + 5, vector<char>(mx_sum + 5));
    for (int i = 0; i <= n; ++i) {
        val[i][0] = true;
    }
    for (int k = 1; k <= n; ++k) {
        for (int x = 1; x <= mx_sum; ++x) {
            if(x - v[k] >= 0)
                val[k][x] |= val[k - 1][x - v[k]];
            val[k][x] |= val[k - 1][x];
        }
    }
    ll c = 0;
    for (int i = 1; i <= mx_sum; ++i) {
        if(val[n][i] == true) {
            c++;
        }
    }
    cout << c << "\n";
    for (int i = 1; i <= mx_sum; ++i) {
        if(val[n][i] == true) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
