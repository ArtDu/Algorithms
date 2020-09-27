// x.pdf -- problem 10
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 1e15;
const ll MOD = 1e9 + 7;
const ld L = -1e8 - 5;
const ld R = 1e8 + 5;
const ld EPS = 1e-12;

#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back

ll n;
ld glob_k = MAXX, glob_b = MAXX, glob_ans = MAXX;
vec<ll> xx, yy;


ld f(ld k, ld b){
    ld s = 0;
    for (int i = 0; i < n; ++i) {
        s += abs(xx[i] - (k * yy[i] + b));
    }
    return s;
}

ld ternary_search_for_k(ld b, ld l, ld r) {
    ld eps = EPS;              //set the error limit here
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(m1, b);      //evaluates the function at m1
        ld f2 = f(m2, b);      //evaluates the function at m2
        if (f1 > f2){
            l = m1;
            if(f2 < glob_ans){
                glob_ans = f2;
                glob_k = m2;
                glob_b = b;
            }
        }
        else {
            r = m2;
            if(f1 < glob_ans){
                glob_ans = f1;
                glob_k = m1;
                glob_b = b;
            }
        }
    }
    return f(l, b);
}

ld ternary_search_for_b(ld l, ld r) {
    ld eps = EPS;              //set the error limit here
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = ternary_search_for_k(m1, L, R);      //evaluates the function at m1
        ld f2 = ternary_search_for_k(m2, L, R);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return ternary_search_for_k(l, L, R);            //return the maximum of f(x) in [l, r]
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    xx.resize(n);
    yy.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> xx[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> yy[i];
    }
    ternary_search_for_b(L, R);
    cout << setprecision(12) << fixed << glob_ans  << " " << glob_k << " " << glob_b << "\n";
    return 0;
}
