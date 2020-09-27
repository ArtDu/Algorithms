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
 
 
ll n, m, q;
vec<vec<ll>> adjMat;
vec<vec<ll>> dist;
 
void floyd_warshall() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else if (adjMat[i][j])
                dist[i][j] = adjMat[i][j];
            else
                dist[i][j] = MAXX;
 
        }
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m >> q;
    adjMat.resize(n + 5, vec<ll>(n + 5, MAXX));
    dist.resize(n + 5, vec<ll>(n + 5));
 
    ll u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adjMat[u][v] = min(adjMat[u][v], w);
        adjMat[v][u] = min(adjMat[u][v], w);
    }
    floyd_warshall();
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        if (dist[u][v] < MAXX)
            cout << dist[u][v] << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
