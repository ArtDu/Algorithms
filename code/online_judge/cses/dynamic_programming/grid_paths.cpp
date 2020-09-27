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
 
ll n;
vector<vector<char>> t(TABLE_SIZE, vector<char>(TABLE_SIZE));
vector<vector<ll>> val(TABLE_SIZE, vector<ll>(TABLE_SIZE));
 
ll solve() {
    if(t[1][1] != '*')
        val[1][1] = 1;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            if(t[y][x] != '*') {
                val[y][x] += val[y - 1][x];
                val[y][x] %= MOD;
                val[y][x] += val[y][x - 1];
                val[y][x] %= MOD;
            }
        }
    }
    return val[n][n];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }
    cout << solve() << "\n";
    return 0;
}
