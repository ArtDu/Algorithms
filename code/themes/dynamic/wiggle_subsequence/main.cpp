// https://leetcode.com/problems/wiggle-subsequence/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 1e15;
const ll MOD = 1e9 + 7;

#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vec<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }


    if(v.size() < 2){
        cout << "1\n";
        return 0;
    }

    vec<ll> up(n);
    vec<ll> down(n);
    up[0] = down[0] = 1;
    for (int i = 1; i < n; ++i) {
        if(v[i] > v[i - 1]){
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        } else if(v[i] < v[i - 1]){
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        } else {
            down[i] = down[i - 1];
            up[i] = up[i - 1];
        }
    }
    cout << max(down[n - 1], up[n - 1]) << "\n";
    return 0;
}
