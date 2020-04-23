/*
 * for random graph without negative cycle
 * print 1e18 if dist[i] > INF
 * print dist[i] if dist[i] exist
 * from s to t;
 *
 * O(V * E)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

class Edge {
public:
    Edge(ll src, ll to, ll w) : src(src), to(to), w(w) {}
    ll src;
    ll to;
    ll w;

};

vector<Edge> edges;
vector<long long> dist;

void bellman_ford(ll n, ll s) {
    dist.resize(n, INF);
    dist[s] = 0;


    for (ll i = 0; i < n - 1; ++i) {
        bool any = false;
        for (auto &edge : edges) {
            ll u, v, w;
            u = edge.src;
            v = edge.to;
            w = edge.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                any = true;
            }
        }
        if (!any)
            break;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, s, t, u, v, w;
    cin >> n >> m >> s >> t;
    --s;
    --t;

    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        edges.emplace_back(u, v, w);
    }
    bellman_ford(n, s);
    if (dist[t] < INF)
        cout << dist[t] << "\n";
    else {
        cout << INF << "\n";
    }

    return 0;
}