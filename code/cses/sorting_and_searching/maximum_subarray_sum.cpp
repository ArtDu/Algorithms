#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e15;
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.first < rhs.first;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n;
    ll sum = 0;
    ll mx = -MAXX;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
        mx = max(mx, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << mx << "\n";
    return 0;
}
