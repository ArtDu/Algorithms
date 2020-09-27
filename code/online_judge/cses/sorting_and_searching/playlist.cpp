#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e15;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x;
    cin >> n;
    set<ll> s;
    queue<ll> q;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = s.find(x);
        if(it == s.end()) {
            s.insert(x);
            q.push(x);
            mx = max(mx, (ll)s.size());
        } else {
            while(x != q.front()) {
                s.erase(q.front());
                q.pop();
            }
            s.erase(q.front());
            q.pop();
            s.insert(x);
            q.push(x);
        }
    }
    cout << mx << "\n";
    return 0;
}
