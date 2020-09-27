/*
based on problem D
https://codeforces.com/gym/100166/attachments
O(V * E)
detect negative cycle:
    print - if vertex on negative cycle
    print * if vertex > INF
    print dist[i] if exist shortest path
*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 5e18;

class Edge {
public:
    Edge(ll src, ll to, ll w) : src(src), to(to), w(w) {}

    ll src;
    ll to;
    ll w;
};

vector<ll> dist;
vector<Edge> edges;
vector<int> used;

ll u, v, w;

void dfs(int u) {
    used[u] = true;
    for (auto &edge : edges) {
        if (u != edge.src) continue;
        v = edge.to;
        if (!used[v])
            dfs(v);
    }
}

void bellman_ford(ll n, ll s) {
    dist.resize(n, INF);
    dist[s] = 0;
    for (ll i = 0; i < n - 1; ++i) {
        for (auto &edge : edges) {
            u = edge.src;
            v = edge.to;
            w = edge.w;
            if ((dist[u] < INF) && (dist[v] > dist[u] + w)) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // check if negative cycle exist
    used.resize(n);
    for (auto &edge : edges) {
        u = edge.src;
        v = edge.to;
        w = edge.w;
        if ((dist[u] < INF) && (dist[v] > dist[u] + w)) {
            if (!used[v])
                dfs(v);
        }
    }
}

int main() {

    //for problem on codeforces
    //    freopen("path.in", "r", stdin);
    //    freopen("path.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n, m, s;
    cin >> n >> m >> s;
    --s;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        edges.emplace_back(u, v, w);
    }
    bellman_ford(n, s);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            cout << "-\n";
        } else if (dist[i] >= INF) {
            cout << "*\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}