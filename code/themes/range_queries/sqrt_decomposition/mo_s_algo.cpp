//https://cses.fi/problemset/task/1734/
//distinct nums queries
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define MP make_pair
#define P pair
#define F first
#define S second
#define MAXX (ll)(2e5 + 5)
#define LG 20
#define MOD 1e9 + 7
 
 
ll block_size;
 
struct Query {
    ll l, r, idx;
 
    bool operator<(Query &other) {
        return MP(l / block_size, r)
               < MP(other.l / block_size, other.r);
    }
};
 
ll n, q;
ll arr[MAXX];
 
ll freq[MAXX];
ll distinct = 0;
 
 
void remove(ll idx) {
    freq[arr[idx]]--;
    if (freq[arr[idx]] == 0) {
        distinct--;
    }
}
 
void add(ll idx) {
    freq[arr[idx]]++;
    if (freq[arr[idx]] == 1) {
        distinct++;
    }
}
 
int get_answer() {
    return distinct;
}
 
void mo_s_algorithm(vec<Query> &queries) {
 
    vec<ll> answers(queries.size());
    sort(queries.begin(), queries.end());
 
    ll cur_l = 1;
    ll cur_r = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (ll i = 0; i < q; ++i) {
        Query qu = queries[i];
        while (cur_l > qu.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < qu.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < qu.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > qu.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[qu.idx] = get_answer();
    }
 
    for (int i = 0; i < q; ++i) {
        cout << answers[i] << "\n";
    }
}
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> q;
 
 
    block_size = (int) sqrt(q + .0) + 1;
 
    map<ll, ll> numsCompress;
    ll comressed_num = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        auto it = numsCompress.find(arr[i]);
        if (it == numsCompress.end()) {
            numsCompress[arr[i]] = comressed_num++;
        }
        arr[i] = numsCompress[arr[i]];
    }
 
    vec<Query> queries(q);
    for (ll i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
 
    mo_s_algorithm(queries);
 
    return 0;
}
