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
    multiset<ll> towers;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = towers.upper_bound(x);
        if(it != towers.end()) { //find
            towers.erase(it);
        }
        towers.insert(x);
    }
    cout << towers.size() << "\n";
    return 0;
}
