#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXX = 1e6;

#define P pair
#define F first
#define S second


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, sum;
    cin >> n >> sum;

    map<ll,ll> mp;
    mp[0] = 1;
    ll a;
    ll pref = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        pref += a;

        // if we don't use mp[0] = 1
        //if(sum == pref)
        //    ans++;

        auto it = mp.find(pref - sum);
        if(it != mp.end()){
            ans += it->S;
        }

        mp[pref]++;
    }
    cout << ans << "\n";
    return 0;
}
