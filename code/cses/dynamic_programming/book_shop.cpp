#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll TABLE_SIZE = 1005;
const ll MOD = 1e9 + 7;
 
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
 
#define MAXX_COST 1e5 + 5
#define MAXX_BOOKS 1e3 + 5
 
ll n, x;
vector<ll> pages;
vector<ll> costs;
 
ll solve() {
    vector<ll> last(x + 5);
    vector<ll> cur(x + 5);
    for (int k = 1; k <= n; ++k) {
        fill(cur.begin(), cur.end(), 0);
        for (int i = 0; i <= x; ++i) {
            if(i - costs[k] >= 0) {
                cur[i] = max(cur[i], last[i - costs[k]] + pages[k]);
            }
            cur[i] = max(cur[i], last[i]);
        }
        last = cur;
    }
    return cur[x];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> x;
    pages.resize(n + 5);
    costs.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> pages[i];
    }
 
    cout << solve() << "\n";
    return 0;
}
