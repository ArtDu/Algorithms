#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicants(n);
    vector<ll> apartments(m);
    for (int i = 0; i < n; ++i) {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    ll ans = 0;
    for(ll i = 0, j = 0; i < n && j < m;) {
        if(applicants[i] - k <= apartments[j] && apartments[j] <= applicants[i] + k) {
           ans++;
           i++; j++;
        } else if(apartments[j] < applicants[i]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
