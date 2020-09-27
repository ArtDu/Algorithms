//https://cses.fi/problemset/task/1643/
#include <iostream>

using namespace std;

using ll = long long;

const ll MAXN = 2 * 1e5 + 5;
const ll MAXV = 1e15;
ll pref[MAXN];

ll n, a;
ll mx, mn;

int main() {

    cin >> n;
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        pref[i] = pref[i - 1] + a;
    }

    mn = pref[0];
    mx = -MAXV;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, pref[i] - mn);
        mn = min(mn, pref[i]);
    }
    cout << mx << "\n";
    return 0;
}
