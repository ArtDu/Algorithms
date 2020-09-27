// problem D -- docs/4.png
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e5 + 5;
const ll MAXX = 4e18 + 5;

#define P pair
#define F first
#define S second
#define pb push_back
#define vec vector

ll n;
vec<ll> dist;
vec<ll> val;
vec<bool> processed;
vec<vec<P<ll, ll>>> adjList;

void dijkstra() {
    priority_queue<P<ll, ll>, vec<P<ll, ll>>, greater<P<ll,ll>>> pq;

    for(int i = 1; i<=n; ++i){
        pq.push({dist[i], i});
    }

    while (!pq.empty()) {
        ll u = pq.top().second; pq.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto &vw : adjList[u]) {
            ll v = vw.F;
            ll w = vw.S;
            if (dist[u] + w < dist[v]) {
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


    ll m, k, w, u, v;
    cin >> n >> m >> k;
    val.resize(n + 5);
    dist.resize(n + 5, MAXX);

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
        dist[i] = -dist[i];
    }

    vec<ll> men(n + 5);
    for (int i = 0; i < k; ++i) {
        cin >> u;
        men[u]++;
    }

    adjList.resize(n + 5);
    processed.resize(n + 5);

    for (int i = 0; i < m; ++i) {
        cin >> w >> u >> v;
        adjList[v].pb({u,w});
    }
    ll ans = 0;
    dijkstra();


    for(ll i=1; i<=n; ++i){
        ans += (men[i]*dist[i]);
    }
    cout <<-ans<<"\n";
    return 0;
}
