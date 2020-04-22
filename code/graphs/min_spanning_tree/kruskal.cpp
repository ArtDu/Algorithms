#include <bits/stdc++.h>

using namespace std;

vector<int> par, sz;

int get(int v) {
    if(par[v] == v) {
        return v;
    }
    par[v] = get(par[v]);
    return par[v];
}

void _union(int u, int v) {
    u = get(u);
    v = get(v);
    if(u == v) {
        return;
    }
    if (sz[u] > sz[v]) {
        swap(v, u);
    }
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    par.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }

    int u, v, w;
    vector<pair<int, pair<int, int> > >  EdgesList(m);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> EdgesList[i].first;
        u--; v--;
        EdgesList[i].second.first = u;
        EdgesList[i].second.second = v;
    }
    sort(EdgesList.begin(), EdgesList.end());

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        w = EdgesList[i].first;
        u = EdgesList[i].second.first;
        v = EdgesList[i].second.second;

        if (get(u) != get(v)) {
            ans += w;
            _union(v, u);
        }
    }
    cout << ans << "\n";
    return 0;
}
