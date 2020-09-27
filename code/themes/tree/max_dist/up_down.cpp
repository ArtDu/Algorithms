//https://cses.fi/problemset/task/1132/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define P pair
#define F first
#define S second
#define MAXX 1e15
#define MOD 1e9 + 7
 
ll n;
vec<ll> child1;
vec<ll> down1;
vec<ll> down2;
vec<ll> up;
vec<vec<ll>> aList;
 
void dfs_up(ll u, ll p) {
    ll mx1 = 0, mx1_child = 0,
            mx2 = 0;
 
    for (auto &v : aList[u]) {
        if (v != p) {
            dfs_up(v, u);
            if (down1[v] + 1 > mx1) {
                mx2 = mx1;
                mx1 = down1[v] + 1;
                mx1_child = v;
            } else if (down1[v] + 1 <= mx1){
                mx2 = max(mx2, down1[v] + 1);
            }
        }
    }
    down1[u] = mx1;
    child1[u] = mx1_child;
    down2[u] = mx2;
}
 
void dfs_down(ll u, ll p) {
 
    for (auto &v : aList[u]) {
 
        if (v != p) {
            if(child1[u] == v){
                up[v] = max(up[u] + 1, 1 + down2[u]);
            } else {
                up[v] = max(up[u] + 1, 1 + down1[u]);
            }
            dfs_down(v, u);
        }
    }
}
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
 
    aList.resize(n + 5);
    child1.resize(n + 5);
    down1.resize(n + 5);
    down2.resize(n + 5);
    up.resize(n + 5);
    ll u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        aList[u].pb(v);
        aList[v].pb(u);
    }
    dfs_up(1, 0);
    dfs_down(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << max(up[i], down1[i]) << " ";
    }
    cout << "\n";
    return 0;
}
