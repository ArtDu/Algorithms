//https://cses.fi/problemset/task/1753
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
const ll MAXX = (ll) (1e7 + 5);
const ll MOD = (ll) (1e9 + 7);
 
ll z[MAXX];
void z_function(string s) {
    ll n = s.size();
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r){
            r = i + z[i] - 1;
            l = i;
        }
    }
}
 
 
int main() {
//    freopen("../test/tmp/test_input.txt", "r", stdin);
//    freopen("../test/tmp/user_output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    string t, p;
    cin >> t >> p;
    string z_str = p + '$' + t;
    z_function(z_str);
 
    ll ans = 0;
    for (int i = p.size() + 1; i < z_str.size(); ++i) {
        if(z[i] == p.size()){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
