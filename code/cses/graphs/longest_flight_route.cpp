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
vec<vec<ll>> from;
vec<bool> visited;
vec<bool> path;
vec<ll> mdist;
vec<ll> p;
vector<ll> s;
bool flag;
 
void dfs(ll u) {
    if(path[u]) {
        flag = true;
        return;
    }
    if(visited[u]) return;
 
    visited[u] = true;
 
    path[u] = true;
    for (auto &v : adj[u]) {
        if(flag) return;
        dfs(v);
        if(flag) return;
    }
    path[u] = false;
 
    s.push_back(u);
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
 
    adj.resize(n + 5);
    from.resize(n + 5);
    mdist.resize(n + 5);
    p.resize(n + 5);
    visited.resize(n + 5);
    path.resize(n + 5);
 
    ll u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        from[v].push_back(u);
    }
    dfs(1);
 
    if(!flag && visited[n]) {
        reverse(s.begin(), s.end());
        mdist[1] = 1;
        for (auto &v : s) {
            for(auto &u : from[v]) {
                if(mdist[u] + 1 > mdist[v]) {
                    mdist[v] = mdist[u] + 1;
                    p[v] = u;
                }
            }
        }
        cout << mdist[n] << "\n";
        ll cur = n;
        vector<ll> st;
        while(cur != 0) {
            st.push_back(cur);
            cur = p[cur];
        }
        for(ll i = st.size() - 1; i >= 0; --i) {
            cout << st[i] << " ";
        }
        cout << "\n";
    }else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
