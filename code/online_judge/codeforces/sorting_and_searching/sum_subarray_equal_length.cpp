//https://codeforces.com/contest/1398/problem/C
//
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vec vector


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll t, n, ans = 0;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        ans = 0;
        vec<ll> p(n + 5);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + (s[i - 1] - '0');
        }
        //pref[r] - pref[l - 1] = r - l + 1
        //pref[r] - pref[l] = r - l
        //pref[r] - r = pref[l] - l
        
        //<pref[l] - l, cnt>
        //<0, 1>
        map<ll, ll> m;
        m[0] = 1;
        for (int i = 1; i <= n; ++i) {
            ll x = p[i] - i;
            auto it = m.find(x);
            if(it != m.end()){
                ans += m[x];
            }
            m[x]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
