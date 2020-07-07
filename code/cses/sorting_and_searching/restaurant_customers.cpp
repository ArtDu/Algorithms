#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
#define IN 1
#define OUT 0
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(2 * n);
    for (int i = 0; i < 2 * n; i+=2) {
        cin >> v[i].first;
        v[i].second = IN;
 
        cin >> v[i + 1].first;
        v[i + 1].second = OUT;
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    ll mx = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (v[i].second == IN) {
            cnt++;
            mx = max(mx, cnt);
        } else {
            cnt--;
        }
    }
    cout << mx << "\n";
    return 0;
}
