//img/d3.png
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

ll N, M;

ll pow(ll a, ll n){
    if (n == 0) return 1;
    if (n == 1) return a;

    if(n % 2 == 0){
        ll tmp = pow(a, n / 2);
        return (tmp * tmp) % M;
    } else {
        return (a * pow(a, n - 1)) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cout << pow(N, N) << "\n";
    return 0;
}


