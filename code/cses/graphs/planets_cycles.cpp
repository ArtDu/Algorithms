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
 
ll n, comp_no, sum;
vec<vec<ll>> g(MAXX), rg(MAXX);
vec<ll> visited(MAXX), component_num(MAXX), val(MAXX), dp(MAXX);
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
 
    component_num[u] = comp_no;
    sum++;
 
    for (auto &v : rg[u]) {
        dfs_rev(v);
    }
}
 
void scc() {
    for (int i = 1; i <= n; ++i) {
        dfs_fwd(i);
    }
 
    visited.assign(MAXX, false);
    comp_no = 1;
    while (!st.empty()) {
        ll u = st.top();
        st.pop();
 
        if (!visited[u]) {
            sum = 0;
            dfs_rev(u);
            dp[comp_no] = sum;
            comp_no++;
        }
    }
}
 
ll dfs(ll v) {
    if (visited[v] || dp[component_num[v]] != 1 || val[v] == v)
        return dp[component_num[v]];
    visited[v] = true;
 
    return dp[component_num[v]] = 1 + dfs(val[v]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
 
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        g[i].pb(val[i]);
        rg[val[i]].pb(i);
    }
 
    scc();
    visited.assign(MAXX, false);
    for (int i = 1; i <= n; ++i) {
        cout << dfs(i) << " ";
    }
    cout << "\n";
    return 0;
}
