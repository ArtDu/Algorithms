//https://cses.fi/problemset/task/1110/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define MP make_pair
#define P pair
#define F first
#define S second
 
const ll LG = 20;
const ll MAXX = (ll) (1e6 + 5);
const ll MOD = (ll) (1e9 + 7);
 
 
const ll A = 911382323, B = 972663749, N = 1000000;
ll h[2 * N + 5], p[2 * N + 5];
 
string s;
 
ll getHash(ll a, ll b) {
    ll ans = 0;
    if (a > 0) {
        ans = (h[b] - h[a - 1] * p[b - a + 1]) % MOD;
        if(ans < 0) ans += MOD;
    } else {
        ans = h[b];
    }
    return ans;
}
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> s;
    ll n = (ll) s.size();
 
    s += s;
 
    h[0] = s[0];
    p[0] = 1;
 
    for (int i = 1; i < s.size(); ++i) {
        h[i] = ((h[i - 1] * A + s[i]) % MOD);
        p[i] = (p[i - 1] * A) % MOD;
    }
 
    ll mn_mn = 0, t_mn;
    ll mn_l, mn_r,
            t_l, t_r,
            mn_m, t_m,
            mn_ans, t_ans;
    for (int i = 1; i + n - 1 < s.size(); ++i) {
        if (s[i] < s[mn_mn]) {
            mn_mn = i;
            continue;
        }
        if (s[i] > s[mn_mn]) continue;
 
        t_mn = i;
        t_l = i, t_r = i + n - 1;
        mn_l = mn_mn, mn_r = mn_mn + n - 1;
 
        while (t_l <= t_r) {
            t_m = (t_l + t_r) / 2;
            mn_m = (mn_l + mn_r) / 2;
            if (getHash(t_mn, t_m) == getHash(mn_mn, mn_m)) {
                mn_ans = mn_m;
                t_ans = t_m;
 
                t_l = t_m + 1;
                mn_l = mn_m + 1;
            } else {
                t_r = t_m - 1;
                mn_r = mn_m - 1;
            }
        }
        if (mn_mn + n - 1 == mn_ans) continue;
        if (s[mn_ans + 1] > s[t_ans + 1]) {
            mn_mn = t_mn;
        }
    }
    cout << s.substr(mn_mn, n) << "\n";
    return 0;
}
