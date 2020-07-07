#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n >> x;
    vector<ll> childs(n);
    for (int i = 0; i < n; ++i) {
        cin >> childs[i];
    }
    sort(childs.begin(), childs.end());
    ll cnt = 0;
    ll i, j;
    for (i = 0, j = childs.size() - 1; i < j;) {
        if(childs[i] + childs[j] <= x) {
            cnt++;
            i++;
            j--;
        } else {
            cnt++;
            j--;
        }
    }
    if(i == j) cnt++;
    cout << cnt << endl;
    return 0;
}
