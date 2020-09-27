//https://cses.fi/problemset/task/1687/
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
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
    ancestor.resize(LG, vec<ll>(n + 5));
 
    for (ll i = 2; i <= n; ++i) {
        cin >> ancestor[0][i];
    }
    for(ll i = 1; i < LG; ++i){
        for (int j = 1; j <= n; ++j) {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }
    ll x, k;
    for (ll i = 0; i < q; ++i) {
        cin >> x >> k;
        for(ll j = 0; j < LG; ++j){
            if((1 << j) & k){
                x = ancestor[j][x];
            }
        }
        cout << (x != 0 ? x : -1) << "\n";
    }
    return 0;
}
