#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll TABLE_SIZE = 1005;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
#define vec vector
 
 
vec<vec<char>> v;
vec<vec<bool>> visited;
 
 
bool dfs(ll y, ll x) {
    if (visited[y][x] || v[y][x] == '#') return false;
 
    visited[y][x] = true;
    dfs(y + 1, x);
    dfs(y - 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
    return true;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
    v.resize(n + 5, vec<char>(m + 5, '#'));
    visited.resize(n + 5, vec<bool>(m + 5));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    ll c = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            c += dfs(i, j);
        }
    }
    cout << c << "\n";
    return 0;
}
