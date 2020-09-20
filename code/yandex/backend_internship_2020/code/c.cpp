#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define P pair
#define pb push_back
#define vec vector
#define mp make_pair

vec<vec<ll>> aList;
vec<bool> visited;
ll sz;

void dfs(ll u) {
    sz++;
    visited[u] = true;
    for (auto &v : aList[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll n, m, u, v;
    cin >> n >> m;
    visited.resize(n + 5);
    aList.resize(n + 5);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        aList[u].pb(v);
        aList[v].pb(u);
    }

    vector<ll> groups;
    for (int i = 0; i < n; ++i) {
        sz = 0;
        if (!visited[i]) {
            dfs(i);
            groups.push_back(sz);
        }
    }
    sort(groups.begin(), groups.end());

    ll k, cap, cnt;
    cin >> k;
    vector<P<ll, ll>> types;
    for (int i = 0; i < k; ++i) {
        cin >> cap >> cnt;
        types.pb({cap, cnt});
    }
    sort(types.begin(), types.end());

    for (auto &group : groups) {
        auto pr = mp(group, 1LL);
        auto it = lower_bound(types.begin(), types.end(), pr);
        if (it == types.end()) {
            cout << "0\n";
            return 0;
        }
        it->second--;
        if (it->second == 0) {
            types.erase(it);
        }
    }
    cout << "1\n";
    return 0;
}
