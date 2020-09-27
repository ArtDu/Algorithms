#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define F first
#define S second
#define IN 1
#define OUT 0
 
 
const ll MAXX = 1e15;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, a, b;
    cin >> n;
    // <time, in\out, idx>
    vector<pair<ll, pair<bool, ll>>> customers;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        customers.pb({a, {IN, i}});
        customers.pb({b + 1, {OUT, i}});
    }
    sort(customers.begin(), customers.end());
 
    //<idx, room>
    map<ll, ll> m;
 
    ll last_room = 1;
    queue<ll> q;
    //<idx, room>
    vector<pair<ll, ll>> ans;
    for (auto &customer : customers) {
        bool in_or_out = customer.S.F;
        //ll time = customer.F;
        ll room;
        ll idx = customer.S.S;
        if (in_or_out == IN) {
            if (q.empty()) {
                room = last_room++;
            } else {
                room = q.front();
                q.pop();
            }
            ans.pb({idx, room});
            m[idx] = room;
        } else {
            room = m[idx];
            q.push(room);
        }
    }
    sort(ans.begin(), ans.end());
    cout << last_room - 1 << "\n";
    for (auto i : ans) {
        cout << i.second << " ";
    }
    return 0;
}
