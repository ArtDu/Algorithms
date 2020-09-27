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
 
vec<bool> visited;
vec<vec<ll>> adjList;
 
bool dfs(ll u) {
    if(visited[u]) return false;
 
    visited[u] = true;
 
    for(auto &v : adjList[u]) {
        dfs(v);
    }
 
    return true;
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m, u, v;
    cin >> n >> m;
    adjList.resize(n + 5);
    visited.resize(n + 5);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vec<ll> ans;
    for (int i = 1; i <= n; ++i) {
        if(dfs(i))
            ans.push_back(i);
    }
    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i - 1] << " " << ans[i] << "\n";
    }
    cout << "\n";
    return 0;
}
