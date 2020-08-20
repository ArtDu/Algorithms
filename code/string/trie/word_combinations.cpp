//https://cses.fi/problemset/task/1731
//trie + dp
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define vec vector
#define pb push_back
#define MP make_pair
#define P pair
#define F first
#define S second
 
const ll LG = 20;
const ll MAXX = (ll) (1e5 + 5);
const ll MOD = (ll) (1e9 + 7);
 
struct Node {
    vec<Node *> child;
    ll cnt;
 
    Node() : cnt(0) { child.resize(26, nullptr); }
};
 
Node *trie = new Node;
string word;
vec<ll> dp;
ll k;
 
void insert(string &s) {
    Node *cur = trie;
    ll c;
    for (int i = 0; i < s.size(); ++i) {
        c = s[i] - 'a';
        if (cur->child[c] == nullptr) {
            cur->child[c] = new Node;
        }
        cur = cur->child[c];
    }
    cur->cnt++;
}
 
void inc(ll x) {
    Node *cur = trie;
    ll c;
    for (ll i = 1; i + x <= word.size(); ++i) {
        c = word[i + x - 1] - 'a';
        if (cur->child[c] == nullptr) break;
        cur = cur->child[c];
        dp[i + x] += ((dp[x] * cur->cnt) % MOD);
        if (dp[i + x] >= MOD) { dp[i + x] -= MOD; }
    }
}
 
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> word;
    cin >> k;
 
    string s;
    for (int i = 0; i < k; ++i) {
        cin >> s;
        insert(s);
    }
 
    dp.resize(word.size() + 5);
    dp[0] = 1;
    for (int i = 0; i < word.size(); ++i) {
        inc(i);
    }
    cout << dp[word.size()] << "\n";
    return 0;
}
