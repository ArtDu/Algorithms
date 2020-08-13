//https://cses.fi/problemset/task/1130
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
ll ans = 0;
 
void dfs(ll u, ll p) {
    for (auto &v : aList[u]) {
        if (v != p) {
            dfs(v, u);
            if(!reserve[u] && !reserve[v]){
                reserve[u] = reserve[v] = true;
                ans++;
            }
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
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}

