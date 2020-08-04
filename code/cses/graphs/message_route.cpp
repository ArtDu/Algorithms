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
vec<ll> dist;
vec<ll> from;
vec<vec<ll>> adjList;
 
ll bfs(ll s, ll f) {
    queue<ll> q;
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto &v : adjList[u]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                from[v] = u;
                q.push(v);
            }
        }
    }
    return dist[f];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m, u, v;
    cin >> n >> m;
    adjList.resize(n + 5);
    visited.resize(n + 5);
    from.resize(n + 5, -1);
    dist.resize(n + 5, -1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    ll ans = bfs(1, n);
    if(ans == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        ll tmp = n;
        stack<ll> st;
        while(tmp != -1) {
            st.push(tmp);
            tmp = from[tmp];
        }
        cout << st.size() << "\n";
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}
