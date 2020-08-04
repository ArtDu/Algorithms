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
 
 
ll n, m;
bool monster = false;
bool hero = false;
bool path = false;
vec<vec<char>> table;
vec<vec<char>> steps;
 
// y, x, to, from
vec<tuple<ll, ll, char, char>> directions = {{-1, 0,  'U', 'D'},
                                             {1,  0,  'D', 'U'},
                                             {0,  1,  'R', 'L'},
                                             {0,  -1, 'L', 'R'}};
 
void cleanFlags() {
    path = false; monster = false; hero = false;
}
 
 
 
void bfs(ll sy, ll sx) {
    steps[sy][sx] = '#';
    vec<vec<bool>> visited (n + 5, vec<bool>(m + 5));
    queue<P<ll, ll>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    ll y, x;
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (auto &[dy, dx, to, from] : directions) {
            if (!visited[y + dy][x + dx] && table[y + dy][x + dx] != '#') {
                if (table[y + dy][x + dx] == 'A') {
                    hero = true;
                } else if (table[y + dy][x + dx] == 'M') {
                    monster = true;
                }
                steps[y + dy][x + dx] = from;
                visited[y + dy][x + dx] = true;
                q.push({y + dy, x + dx});
            }
        }
        if (monster) {
            return;
        }
        if (hero) {
            path = true;
            return;
        }
    }
 
}
 
void startBfs(ll y, ll x) {
    if(table[y][x] == 'A')
        path = true;
 
    if (table[y][x] == '.')
        bfs(y, x);
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll a_y = -1, a_x = -1;
    cin >> n >> m;
    table.resize(n + 5, vec<char>(m + 5, '#'));
    steps.resize(n + 5, vec<char>(m + 5, '#'));
//    visited.resize(n + 5, vec<bool>(m + 5));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> table[i][j];
            if (table[i][j] == 'A') {
                tie(a_y, a_x) = make_pair(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cleanFlags();
        startBfs(i, 1);
        if (path) {
            break;
        }
 
        cleanFlags();
        startBfs(i, m);
        if (path) {
            break;
        }
    }
 
    if (!path) {
        for (int i = 1; i <= m; ++i) {
            cleanFlags();
            startBfs(1, i);
            if (path) {
                break;
            }
 
            cleanFlags();
            startBfs(n, i);
            if (path) {
                break;
            }
        }
    }
    if (path) {
        cout << "YES\n";
        string route;
        ll y = a_y, x = a_x;
        while (steps[y][x] != '#') {
            route += steps[y][x];
            for (auto &[dy, dx, to, from] : directions) {
                if (steps[y][x] == to) {
                    y += dy;
                    x += dx;
                    break;
                }
            }
        }
        cout << route.size() << "\n";
        cout << route << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
