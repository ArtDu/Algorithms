// K problem
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 1e15;
const ll MOD = 998244353;
const ll base = 1000000000;
const ll sz = 9;


#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back

ll tr(string s){
    ll sum = 0;
    ll x = 10;
    for (char i : s) {
        sum = sum * x + ll(i - '0');
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    vec<ll> a;
    for (ll i = s.size(); i > 0; i -= sz)
        if (i < sz)
            a.push_back(tr(s.substr(0, i)));
        else
            a.push_back(tr(s.substr(i - sz, sz)));
    ll carry = 0;
    for (ll i = a.size() - 1; i >= 0; --i) {
        ll cur = a[i] + carry * base;
        a[i] = cur / MOD;
        carry = cur % MOD;
    }

    cout << carry << "\n";
    return 0;
}
