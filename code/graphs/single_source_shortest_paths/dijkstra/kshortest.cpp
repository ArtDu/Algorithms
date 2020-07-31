// https://cses.fi/problemset/task/1196/

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

ll n, m, k;
vec<vec<P<ll, ll>>> adj;
vec<ll> dist;
vec<ll> cnt;

void dijkstra(ll s) {
    priority_queue<P<ll, ll>, vec<P<ll, ll>>, greater<>> pq;

    pq.push({0, s});

    while (!pq.empty() && cnt[n] < k) {
        ll u = pq.top().S;
        ll d = pq.top().F;
        pq.pop();

        cnt[u]++;
        if(u == n) {
            dist.push_back(d);
        }

        if(cnt[u] <= k) {
            for (auto &[v, w] : adj[u]) {
                pq.push({d + w, v});
            }
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    adj.resize(n + 5);
    cnt.resize(n + 5);

    ll u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1);
    sort(dist.begin(), dist.end());
    for (ll i = 0; i < k; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
