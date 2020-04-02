#include <iostream>

using namespace std;

const int MAXN = 300500;
const int MAXV = 1000000050;
long pref[MAXN];

int n, a;
long mx, mn;

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