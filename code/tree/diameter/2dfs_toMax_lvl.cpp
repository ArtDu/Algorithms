//https://cses.fi/problemset/task/1131/
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
vec<bool> reserve;
vec<vec<ll>> aList;
ll mx_lvl = 0;
ll mx_lvl_node = 0;
 
void dfs(ll u, ll p, ll lvl) {
    if(lvl > mx_lvl){
        mx_lvl = lvl;
        mx_lvl_node = u;
    }
    for (auto &v : aList[u]) {
        if (v != p) {
            dfs(v, u, lvl+1);
        }
    }
}
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
 
    reserve.resize(n + 5);
    aList.resize(n + 5);
    ll u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        aList[u].pb(v);
        aList[v].pb(u);
    }
    u = 1;
    dfs(u, 0, 0);
    u = mx_lvl_node;
    mx_lvl_node = 0; mx_lvl = 0;
    dfs(u, 0, 0);
    cout << mx_lvl << "\n";
    return 0;
}

