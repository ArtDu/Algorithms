#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e15;
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
 
 
ll n, m;
vec<ll> dist;
vec<bool> processed;
vec<vec<P<ll, ll>>> adjList;
 
void djkstra(ll s) {
    dist[s] = 0;
    priority_queue<P<ll, ll>, vec<P<ll, ll>>, greater<>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        ll u = pq.top().second; pq.pop();
        if(processed[u]) continue;
        processed[u] = true;
        for(auto &vw : adjList[u]) {
            ll v = vw.F; ll w = vw.S;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    adjList.resize(n + 5);
    dist.resize(n + 5, MAXX);
    processed.resize(n + 5);
 
    ll u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
//        adjList[v].push_back({u, w});
    }
    djkstra(1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
