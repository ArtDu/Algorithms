//https://cses.fi/problemset/task/1110/
//O(n*(Logn)^2)
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
const ll MAXX = (ll) (1e15 + 5);
const ll MOD = (ll) (1e9 + 7);
 
 
vec<ll> suffix_array_construction(string &s) {
    ll n = (ll) s.size();
 
    vec<P<ll, ll>> char_id(n);
    for (int i = 0; i < n; ++i) {
        char_id[i] = {s[i], i};
    }
    sort(char_id.begin(), char_id.end());
 
    vec<ll> l(n);
    ll labels = 0;
    l[char_id[0].S] = labels++;
    for (int i = 1; i < n; ++i) {
        if (char_id[i].F != char_id[i - 1].F) {
            l[char_id[i].S] = labels++;
        } else {
            l[char_id[i].S] = labels - 1;
        }
    }
 
    //fst, snd, id
    vec<P<P<ll,ll>,ll>> pr(n);
    for (int i = 0; (1LL << i) < n; ++i) {
        ll sz = (1LL << i);
 
        for (int j = 0; j < n; ++j) {
 
            if(j + sz < n){
                pr[j] = {{l[j], l[j + sz]}, j};
            } else {
                pr[j] = {{l[j], 0}, j};
            }
        }
        sort(pr.begin(), pr.end());
 
        labels = 0;
        l[pr[0].S] = labels++;
        for (int i = 1; i < n; ++i) {
            if (pr[i].F != pr[i - 1].F) {
                l[pr[i].S] = labels++;
            } else {
                l[pr[i].S] = labels - 1;
            }
        }
    }
    return l;
}
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    string s;
    cin >> s;
    vector<ll> l = suffix_array_construction(s);
    ll mn = MAXX;
    ll mn_id = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(l[i] < mn){
            mn = l[i];
            mn_id = i;
        }
    }
    cout << s.substr(mn_id) << s.substr(0,mn_id) << "\n";
    return 0;
}
