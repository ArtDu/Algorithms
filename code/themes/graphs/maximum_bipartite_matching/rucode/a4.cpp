#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<int> used;
vector<vector<int>> adj;
vector<int> par;
int cnt;

bool dfs(int u) {
    if (used[u] == cnt)
        return false;
    used[u] = cnt;

    for (auto &v : adj[u]) {
        if (par[v] == -1) {
            par[v] = u;
            return true;
        }
    }

    for (auto &v : adj[u]) {
        if (dfs(par[v])) {
            par[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a;
    cin >> n >> m;
    used.resize(n + m + 5, 0);
    adj.resize(n + m + 5);
    par.resize(n + m + 5, -1);
    for (int i = 1; i < n + 1; ++i) {
        while (true) {
            cin >> a;
            if (a == 0)
                break;
            adj[i].push_back(a + n);
            adj[a + n].push_back(i);
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        cnt++;
        dfs(i);
    }
    int ans = 0;
    for (auto &j : par)
        if (j != -1)
            ans++;

    cout << ans << "\n";
    for (int j = 1; j < par.size(); ++j) {
        if (par[j] != -1) {
            cout << par[j] << " " << j - n << "\n";
        }
    }

    return 0;
}
