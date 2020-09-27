//https://cses.fi/problemset/task/1190/
#include <bits/stdc++.h>
 
using namespace std;
 
#define vec vector
#define P pair
#define F first
#define S second
#define MAXX 1e15
 
using ll = long long;
 
ll n, m;
 
struct node {
    ll sum;
    ll pref;
    ll suff;
    ll ans;
};
 
vec<node> tree;
 
void upd(ll k, ll x) {
    node l, r;
    k += n;
    tree[k] = {x, x, x, x};
    for (k /= 2; k >= 1; k /= 2) {
        l = tree[2 * k];
        r = tree[2 * k + 1];
        tree[k].sum = l.sum + r.sum;
        tree[k].pref = max(l.sum + r.pref, l.pref);
        tree[k].suff = max(r.sum + l.suff, r.suff);
        tree[k].ans = max(l.suff + r.pref, max(l.ans, r.ans));
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
 
    ll old_n = n;
    n *= 4;
 
 
    tree.resize(2 * n + 5);
 
    ll k, x;
    for (int i = 0; i < old_n; ++i) {
        cin >> x;
        upd(i, x);
    }
    for (int i = 0; i < m; ++i) {
        cin >> k >> x;
        upd(--k, x);
        cout << tree[1].ans << "\n";
    }
    return 0;
}
