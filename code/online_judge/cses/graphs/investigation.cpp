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
vec<vec<P<ll, ll>>> adj;
 
vec<bool> processed;
 
vec<ll> dist;
vec<ll> cnt;
vec<ll> maxx;
vec<ll> minn;
 
 
void dijkstra(ll s) {
    priority_queue<P<ll,ll>, vec<P<ll,ll>>, greater<>> pq;
    dist[s] = 0;
    cnt[s] = 1;
    maxx[s] = 0;
    minn[s] = 0;
    pq.push({0, s});
 
    while(!pq.empty()) {
        ll u = pq.top().S; pq.pop();
        if(processed[u]) continue;
 
        processed[u] = true;
        for(auto &[v, w] : adj[u]){
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                maxx[v] = maxx[u] + 1;
                minn[v] = minn[u] + 1;
                pq.push({dist[u] + w, v});
            } else if (dist[u] + w == dist[v]) {
                (cnt[v] += cnt[u]) %= MOD;
                maxx[v] = max(maxx[v], maxx[u] + 1);
                minn[v] = min(minn[v], minn[u] + 1);
            }
        }
    }
    
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
 
    adj.resize(n + 5);
 
    processed.resize(n + 5);
 
 
    dist.resize(n + 5, MAXX);
    cnt.resize(n + 5);
    maxx.resize(n + 5, -MAXX);
    minn.resize(n + 5, MAXX);
 
 
    ll u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
 
    dijkstra(1);
 
    cout << dist[n] << " " << cnt[n] << " "
         << minn[n] << " " << maxx[n] << "\n";
    return 0;
}
