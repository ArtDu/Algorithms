#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MAXX = 1e6;
 
#define P pair
#define F first
#define S second
 
struct class_cmp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F && lhs.S > rhs.S;
    }
};
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F > rhs.F || lhs.S > rhs.S;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, x, id;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums[i] = x;
        v[i] = make_pair(x, i);
    }
    sort(v.begin(), v.end());
    set<ll,greater<>> ids;
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        tie(x, id) = v[i];
        ll find_id = id;
        while(true) {
            auto it = ids.upper_bound(find_id);
            if(it != ids.end()) {
                if(nums[*it] == x) {
                    find_id = *it;
                    continue;
                }
                ans[id] = *it;
            } else {
                ans[id] = -1;
            }
            break;
        }
 
        ids.insert(id);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}
