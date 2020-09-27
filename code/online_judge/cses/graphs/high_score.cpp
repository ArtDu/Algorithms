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
vec<tuple<ll, ll, ll>> edges;
vec<ll> dist;
 
void bellman_ford() {
    bool update;
    dist[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        update = false;
        for(auto &[u, v, w] : edges) {
            if(dist[v] < MAXX && dist[u] != -MAXX && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                update = true;
            }
        }
        if(!update) {
            break;
        }
    }
 
    for (int i = 0; i < n - 1; ++i) {
        update = false;
        for(auto &[u, v, w] : edges) {
            if(dist[v] < MAXX && dist[u] != -MAXX && dist[u] + w > dist[v]) {
                dist[v] = MAXX;
                update = true;
            }
        }
        if(!update) {
            break;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    dist.resize(n + 5, -MAXX);
    edges.resize(m);
 
    ll u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    bellman_ford();
    if(dist[n] < MAXX)
        cout << dist[n] << "\n";
    else
        cout << "-1\n";
    return 0;
}
