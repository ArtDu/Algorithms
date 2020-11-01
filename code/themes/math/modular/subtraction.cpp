//b3 problem -- img/b3.png

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 5e18;
const ll MOD = 1e6 + 7;


#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back
#define BEG second
#define END first


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    a = (a * a) % MOD;
    b = (b * b) % MOD;
    cout << ((a - b) + MOD) % MOD << "\n";
    return 0;
}


