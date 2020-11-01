//img/e3.png
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 5e18;
const ll MOD = 1e9 + 7;


#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back
#define BEG second
#define END first

ll pow(ll a, ll n){
    if (n == 0) return 1;
    if (n == 1) return a;

    if(n % 2 == 0){
        ll tmp = pow(a, n / 2);
        return (tmp * tmp) % MOD;
    } else {
        return (a * pow(a, n - 1)) % MOD;
    }
}

ll inv(ll x){
    return pow(x, MOD - 2);
}

ll real_mod(ll x){
    return ((x % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << real_mod(real_mod(a * inv(b)) + real_mod(c * inv(d))) << "\n";
    return 0;
}


