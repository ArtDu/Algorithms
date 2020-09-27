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
 
struct class_cmp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F && lhs.S > rhs.S;
    }
};
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F > rhs.F || lhs.S > rhs.S;
}
 
vec<ll> colors;
vec<bool> visited;
vec<vec<ll>> adjList;
bool bipatite = true;
 
void dfs(ll u, ll color) {
 
    if (colors[u] != 0 && colors[u] != color) {
        bipatite = false;
        return;
    }
    if(visited[u]) return;
 
    visited[u] = true;
    colors[u] = color;
    if (color == 1) {
        color = 2;
    } else {
        color = 1;
    }
 
    for (auto &v : adjList[u]) {
        dfs(v, color);
 
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m, u, v;
    cin >> n >> m;
    adjList.resize(n + 5);
    colors.resize(n + 5);
    visited.resize(n + 5);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!colors[i]) {
            dfs(i, 1);
        }
    }
    if (bipatite) {
        for (int i = 1; i <= n; ++i) {
            cout << colors[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";
    return 0;
}
