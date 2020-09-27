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
 
ll n,m;
vec<vec<ll>> g, rg;
vec<ll> vis1;
vec<ll> vis2;
 
void dfs1(ll u){
    if(vis1[u]) return;
    vis1[u] = true;
 
    for (auto &v : g[u]) {
        dfs1(v);
    }
}
 
void dfs2(ll u){
    if(vis2[u]) return;
    vis2[u] = true;
 
    for (auto &v : rg[u]) {
        dfs2(v);
    }
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    g.resize(n + 5);
    rg.resize(n + 5);
    vis1.resize(n + 5);
    vis2.resize(n + 5);
 
    ll u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].pb(v);
        rg[v].pb(u);
    }
 
    dfs1(1);
    dfs2(1);
 
    bool oneComponent = true;
    for(ll i = 1; i <= n; ++i){
        if(!vis1[i] || !vis2[i]){
            oneComponent = false;
        }
    }
    if(oneComponent) cout << "YES\n";
    else {
        cout << "NO\n";
        for (int i = 1; i <= n; ++i) {
            if(!vis1[i]){
                cout << "1 " << i << "\n";
                return 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if(!vis2[i]){
                cout << i << " 1" << "\n";
                return 0;
            }
        }
    }
    return 0;
}
