#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MAXX = 2e5 + 5;
const ll LG = 20;
const ll MOD = 1e9 + 7;

#define P pair
#define F first
#define S second
#define pb push_back
#define vec vector

ll n, q;
vec<ll> succ(MAXX);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> succ[i];
    }


    for (int i = 1; i <= n; ++i) {
        ll x = i;
        ll a = succ[x];
        ll b = succ[succ[x]];

        while(a != b){
            a = succ[a];
            b = succ[succ[b]];
        }

        ll mu = 0;
        a = x;
        while(a != b){
            a = succ[a];
            b = succ[b];
            mu++;
        }

        ll lam = 1;
        b = succ[a];
        while(a != b){
            b = succ[b];
            lam++;
        }
        cout << mu + lam << " ";
    }
    cout << "\n";
    return 0;
}

