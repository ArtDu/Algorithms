//https://cses.fi/problemset/task/1135/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define P pair
#define F first
#define S second
#define MAXX 4e5 + 5
#define LG 20
#define MOD 1e9 + 7
 
ll n, q;
vec<vec<ll>> aList;
vec<vec<ll>> st;
vec<vec<ll>> stIds;
vec<ll> Log(MAXX);
vec<ll> inOrderEuler;
vec<ll> inOrderEulerLevels;
vec<ll> firstPos;
vec<ll> levels;
ll dfs_timer = 1;
 
void dfs(ll u, ll p, ll lvl) {
    levels[u] = lvl;
 
    inOrderEuler[dfs_timer] = u;
    inOrderEulerLevels[dfs_timer] = levels[u];
    firstPos[u] = dfs_timer;
    dfs_timer++;
 
    for (auto &v : aList[u]) {
        if (v != p) {
            dfs(v, u, lvl + 1);
            inOrderEuler[dfs_timer] = u;
            inOrderEulerLevels[dfs_timer] = levels[u];
            dfs_timer++;
        }
    }
 
 
}
 
void initSparseTable() {
    st.resize(LG, vec<ll>(2 * n + 5));
    stIds.resize(LG, vec<ll>(2 * n + 5));
    for (int i = 1; i <= 2 * n; ++i) {
        stIds[0][i] = i;
        st[0][i] = inOrderEulerLevels[i];
    }
 
    Log[1] = 0;
    for (int i = 2; i < MAXX; ++i) {
        Log[i] = Log[i / 2] + 1;
    }
 
    ll sz;
    for (int i = 1; i < LG; ++i) {
        sz = 1LL << (i - 1);
        for (int j = 1; j + sz <= 2 * n; ++j) {
            if (st[i - 1][j] < st[i - 1][j + sz]) {
                st[i][j] = st[i - 1][j];
                stIds[i][j] = stIds[i - 1][j];
            } else {
                st[i][j] = st[i - 1][j + sz];
                stIds[i][j] = stIds[i - 1][j + sz];
            }
        }
    }
 
}
 
ll getMinId(ll a, ll b) {
    ll sz = b - a + 1;
    sz = Log[sz];
    ll l = st[sz][a],
            l_id = stIds[sz][a];
    ll r = st[sz][b - (1LL << sz) + 1],
            r_id = stIds[sz][b - (1LL << sz) + 1];
    if (l < r) {
        return inOrderEuler[l_id];
    } else {
        return inOrderEuler[r_id];
    }
}
 
ll lca(ll a, ll b) {
    a = firstPos[a];
    b = firstPos[b];
    if(a > b) swap(a, b);
 
    return getMinId(a, b);
}
 
ll dist(ll a, ll b) {
    ll anc = lca(a, b);
    return levels[a] + levels[b] - 2 * levels[anc];
}
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
    aList.resize(n + 5);
    levels.resize(n + 5);
    firstPos.resize(n + 5);
    inOrderEuler.resize(2 * n + 5);
    inOrderEulerLevels.resize(2 * n + 5);
 
    ll u, v;
    for (ll i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        aList[u].pb(v);
        aList[v].pb(u);
    }
 
 
    dfs(1, 0, 0);
    initSparseTable();
    ll a, b;
    for (ll i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << dist(a, b) << "\n";
    }
    return 0;
}
