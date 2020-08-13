//https://cses.fi/problemset/task/1688/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define P pair
#define F first
#define S second
#define MAXX 1e15
#define LG 20
#define MOD 1e9 + 7
 
ll n, q;
vec<vec<ll>> ancestor;
vec<vec<ll>> aList;
vec<ll> levels, time_in, time_out;
ll dfs_timer = 0;
 
void dfs(ll u, ll p, ll lvl) {
    time_in[u] = dfs_timer++;
    levels[u] = lvl;
 
    for (auto &v : aList[u]) {
        if (v != p) {
            dfs(v, u, lvl + 1);
        }
    }
    time_out[u] = dfs_timer++;
}
 
ll getKth(ll x, ll k) {
    for (ll j = 0; j < LG; ++j) {
        if ((1 << j) & k) {
            x = ancestor[j][x];
        }
    }
    return x;
}
 
bool isAncestor(ll anc, ll b){
    return (time_in[anc] <= time_in[b] && time_out[b] <= time_out[anc]);
}
 
ll binSearch(ll a, ll b) {
    ll l = 0, r = levels[a], m, ans = a;
    ll tmp_a;
    while (l <= r) {
        m = (l + r) / 2;
        tmp_a = getKth(a, m);
        if (isAncestor(tmp_a, b)) {
            ans = tmp_a;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}
 
ll lca(ll a, ll b){
    if(levels[a] != levels[b]){
        if(levels[a] < levels[b]){
            swap(a,b);
        }
        ll diff = levels[a] - levels[b];
        a = getKth(a, diff);
    }
    return binSearch(a, b);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
    aList.resize(n + 5);
    levels.resize(n + 5);
    time_in.resize(n + 5);
    time_out.resize(n + 5);
    ancestor.resize(LG, vec<ll>(n + 5));
 
    ll u;
    for (ll v = 2; v <= n; ++v) {
        cin >> u;
        ancestor[0][v] = u;
        aList[u].pb(v);
        aList[v].pb(u);
    }
    for (ll i = 1; i < LG; ++i) {
        for (ll j = 1; j <= n; ++j) {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }
 
    dfs(1, 0, 0);
    ll a, b;
    for (ll i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}
