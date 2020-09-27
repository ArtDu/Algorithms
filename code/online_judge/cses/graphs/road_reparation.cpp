#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 2e5 + 5;
const ll LG = 20;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
#define pb push_back
#define vec vector
 
 
ll n, m;
ll u, v, w;
vec<tuple<ll, ll, ll>> edges;
 
vec<ll> p;
vec<ll> sz;
 
 
ll find(ll a){
    if(p[a] == a)
        return a;
    return p[a] = find(p[a]);
}
 
bool same(ll a, ll b){
    return find(a) == find(b);
}
 
void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
 
    p[b] = a;
    sz[a] += sz[b];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
 
    edges.resize(m);
    p.resize(n + 5);
    sz.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
 
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(auto &[w, u, v] : edges){
        if(!same(u, v)) {
            ans += w;
            unite(u, v);
        }
    }
 
    ll agent = find(1);
    for (int i = 2; i <= n; ++i) {
        if(find(i) != agent) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}

