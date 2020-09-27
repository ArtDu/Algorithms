#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e15;
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
 
ll n, m;
vec<vec<ll>> adj;
vec<ll> visited;
vec<ll> q;
vec<bool> path;
bool flag = false;
 
 
void dfs(ll u) {
    if(path[u]) {
        q.push_back(u);
 
        ll i;
        for(i = 0; i < q.size() && q[i] != u; i++);
        q.erase(q.begin(), q.begin() + i);
 
        flag = true;
        return;
    }
 
    if(visited[u]) return;
    visited[u] = true;
 
    q.push_back(u);
    path[u] = true;
    for(auto &v : adj[u]) {
        if(flag) return;
        dfs(v);
        if(flag) return;
    }
    q.erase(q.end() - 1);
    path[u] = false;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    adj.resize(n + 5);
    visited.resize(n + 5);
    path.resize(n + 5);
    ll u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
//        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        if(flag) break;
    }
    if(flag){
        cout << q.size() << "\n";
        for(auto &i : q)
            cout << i << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}

