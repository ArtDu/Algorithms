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
 
vector<vector<ll>> val;
string s1, s2;
 
 
// idx from 1 to n
ll solve(ll n, ll m) {
    for (int i = 1; i <= n; ++i) {
        val[i][0] = i;
    }
    for (int i = 1; i <= m; ++i) {
        val[0][i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                val[i][j] = val[i - 1][j - 1];
            } else {
                val[i][j] = min(val[i - 1][j - 1], val[i - 1][j]);
                val[i][j] = min(val[i][j], val[i][j - 1]);
                val[i][j] += 1;
            }
        }
    }
    return val[n][m];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> s1 >> s2;
    val.resize(s1.size() + 5, vector<ll>(s2.size() + 5));
    cout << solve(s1.size(), s2.size()) << "\n";
    return 0;
}
