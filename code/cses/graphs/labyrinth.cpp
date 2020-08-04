#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e6;
const ll TABLE_SIZE = 1005;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
#define vec vector
 
struct class_cmp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F && lhs.S > rhs.S;
    }
};
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F > rhs.F || lhs.S > rhs.S;
}
 
vec<vec<char>> v;
vec<vec<bool>> visited;
vec<vec<ll>> dist;
vec<vec<char>> pr;
 
 
bool bfs(ll sy, ll sx) {
    vec<tuple<ll, ll, char>> fromTo = {{0,  1,  'R'},
                                       {0,  -1, 'L'},
                                       {-1,  0,  'U'},
                                       {1, 0,  'D'}};
 
    queue<pair<ll, ll>> q;
    q.push({sy, sx});
    dist[sy][sx] = 0;
    visited[sy][sx] = true;
 
    while (!q.empty()) {
        ll y, x;
        tie(y, x) = q.front();
        q.pop();
        for (auto &[dy, dx, from] : fromTo) {
            if (!visited[y + dy][x + dx] && v[y + dy][x + dx] != '#') {
                visited[y + dy][x + dx] = true;
                dist[y + dy][x + dx] = dist[y][x] + 1;
                pr[y + dy][x + dx] = from;
                q.push({y + dy, x + dx});
            }
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
    v.resize(n + 5, vec<char>(m + 5, '#'));
    visited.resize(n + 5, vec<bool>(m + 5));
    dist.resize(n + 5, vec<ll>(m + 5, -1));
    pr.resize(n + 5, vec<char>(m + 5, '#'));
 
    P<ll, ll> s, f;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'A') {
                s = {i, j};
            } else if (v[i][j] == 'B') {
                f = {i, j};
            }
        }
    }
    bfs(s.F, s.S);
    if (dist[f.F][f.S] != -1) {
        cout << "YES\n";
        cout << dist[f.F][f.S] << "\n";
        ll y, x;
        tie(y, x) = f;
        string path;
        while(pr[y][x] != '#') {
            path += pr[y][x];
            switch (pr[y][x]) {
                case 'R':
                    x--;
                    break;
                case 'L':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
 
    } else {
        cout << "NO\n";
    }
    return 0;
}
