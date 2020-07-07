#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e15;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll m = v.size() / 2;
    ll num = v[m];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] != num)
            ans += abs(v[i] - num);
    }
    cout << ans << "\n";
    return 0;
}
