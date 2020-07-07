#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
 
    sort(v.begin(), v.end());
    ll cnt = 1;
    for (int i = 1; i < v.size(); ++i) {
        if(v[i] != v[i-1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
