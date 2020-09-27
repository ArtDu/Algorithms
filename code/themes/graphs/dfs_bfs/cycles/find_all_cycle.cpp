#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 1e15;
const ll MOD = 1e9 + 7;

#define P pair
#define F first
#define S second
#define vec vector

ll n, m;
vec<vec<P<ll,ld>>> adj;
vec<ll> visited;
vec<ll> q;
vec<bool> path;
bool flag = false;


void dfs(ll u) {
    if(path[u]) {
        vector<ll> q_tmp = q;
        q_tmp.push_back(u);

        ll i;
        for(i = 0; i < q_tmp.size() && q_tmp[i] != u; i++);
        q_tmp.erase(q_tmp.begin(), q_tmp.begin() + i);

        ld s = 1;
        ll _u = q_tmp[0];
        for(i = 1; i < q_tmp.size(); ++i){
            for(auto &[_v, _w] : adj[_u]){
                if(q_tmp[i] == _v){
                    s *= _w;
                    _u = _v;
                    break;
                }
            }
        }
        if(s > 1)
            flag = true;
        return;
    }

    if(visited[u]) return;
    visited[u] = true;

    q.push_back(u);
    path[u] = true;
    for(auto &[v, w] : adj[u]) {
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
    ld w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        if(flag) break;
    }
    if(flag){
        cout << "inadmissible\n";
    } else {
        cout << "admissible\n";
    }
    return 0;
}
