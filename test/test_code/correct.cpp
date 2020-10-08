#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll CNT = 1e5 + 5;
const ll MAXX = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define vec vector

ll n, k;
ll v[CNT];
bool used[CNT];
ll mx = 0;
void search(ll idx){
    if(idx == k){
        ll i;
        for (i = 0; i < n && !used[i]; ++i) {}

        ll l = i;
        ll mn = MAXX;
        for (ll r = i + 1; r < n; ++r) {
            if(used[r]){
                mn = min(mn, v[r] - v[l]);
                l = r;
            }
        }
        mx = max(mx, mn);
    } else {
        for (int i = 0; i < n; ++i) {
            if(!used[i]) {
                used[i] = true;
                search(idx + 1);
                used[i] = false;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    search(0);
    cout << mx << "\n";
    return 0;
}