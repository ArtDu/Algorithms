#include <iostream>

using namespace std;

const int MAXN = 300500;
long pref[MAXN];

int n, q, l, r, a;

int main() {

    cin >> n >> q;
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        pref[i] = pref[i - 1] + a;
    }

    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << "\n";
    }
    return 0;
}