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
 
ll n, q, x, comp_sz;
vec<vec<ll>> g(MAXX), rg(MAXX), cycle(MAXX), scc_tree(MAXX), succ(LG, vec<ll>(MAXX));
vec<ll> visited(MAXX), pos_in_cycle(MAXX), component_num(MAXX), ways_out(MAXX), lvl(MAXX);
stack<ll> st;
 
void dfs_fwd(ll u) {
    if (visited[u]) return;
 
    visited[u] = true;
    for (auto &v : g[u]) {
        dfs_fwd(v);
    }
    st.push(u);
}
 
void dfs_rev(ll u) {
    if (visited[u]) return;
    visited[u] = true;
 
    component_num[u] = comp_sz;
    pos_in_cycle[u] = cycle[comp_sz].size();
    cycle[comp_sz].pb(u);
 
    for (auto &v : rg[u]) {
        dfs_rev(v);
    }
}
 
void scc() {
    for (int i = 1; i <= n; ++i) {
        dfs_fwd(i);
    }
 
    visited.assign(MAXX, false);
    comp_sz = 1;
    while (!st.empty()) {
        ll u = st.top();
        st.pop();
 
        if (!visited[u]) {
            dfs_rev(u);
            comp_sz++;
        }
    }
}
 
void dfs(ll u, ll p) {
 
    lvl[u] = lvl[p] + 1;
    succ[0][u] = p;
    for (auto &v : scc_tree[u]) {
        dfs(v, u);
    }
}
 
ll go(ll x, ll k){
    for(ll i = 0; i < LG; ++i){
        if((1LL << i) & k){
            x = succ[i][x];
        }
    }
    return x;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
 
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        g[i].pb(x);
        rg[x].pb(i);
    }
 
    scc();
 
    //build inverted SCCs tree
    for (int u = 1; u <= n; ++u) {
        for (auto &v : g[u]) {
            if (component_num[u] != component_num[v]) {
                scc_tree[component_num[v]].push_back(component_num[u]);
                ways_out[component_num[u]]++;
            }
        }
    }
    for (int u = 1; u < comp_sz; ++u) {
        if (!ways_out[u]) {
            scc_tree[comp_sz].pb(u);
        }
    }
    dfs(comp_sz, 0);
    for (int i = 1; i < LG; ++i) {
        for (int j = 1; j < comp_sz; ++j) {
            succ[i][j] = succ[i - 1][succ[i - 1][j]];
        }
    }
 
    ll u, v;
    while (q--) {
        cin >> u >> v;
        if (u == v) {
            cout << "0\n";
        } else if (component_num[u] == component_num[v]) {
            if (pos_in_cycle[v] < pos_in_cycle[u])
                cout << pos_in_cycle[u] - pos_in_cycle[v] << "\n";
            else
                cout << cycle[component_num[v]].size() - (pos_in_cycle[v] - pos_in_cycle[u]) << "\n";
        } else {
            if(lvl[component_num[u]] <= lvl[component_num[v]])
                cout << "-1\n";
            else {
                ll diff = lvl[component_num[u]] - lvl[component_num[v]];
                ll comp_before_compV = go(component_num[u], diff - 1);
                ll compV = go(component_num[u], diff);
                if(compV != component_num[v])
                    cout << "-1\n";
                else {
                    u = g[cycle[comp_before_compV][0]][0];
                    ll ans = diff;
                    if(u != v){
                        if (pos_in_cycle[v] < pos_in_cycle[u])
                            ans += pos_in_cycle[u] - pos_in_cycle[v] ;
                        else
                            ans += cycle[component_num[v]].size() - (pos_in_cycle[v] - pos_in_cycle[u]);
                    }
 
                    cout << ans << "\n";
                }
            }
        }
    }
    return 0;
}
