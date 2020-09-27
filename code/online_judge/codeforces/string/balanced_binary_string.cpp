//https://codeforces.com/contest/1405/problem/C
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll N = 1e5 + 5;
const ll MAXX = 4e18 + 5;
 
#define P pair
#define F first
#define S second
#define pb push_back
#define vec vector
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
 
    ll t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        bool correct = true;
        ll z = 0, o = 0, q = 0;
        for (int i = 0; i < k; ++i) {
            bool zero = false, one = false;
            for (int j = i; j < n; j += k) {
                if (s[j] == '0')
                    zero = true;
                if (s[j] == '1')
                    one = true;
            }
            if (zero && one) {
                correct = false;
                break;
            } else if (zero) {
                z++;
            } else if (one) {
                o++;
            } else {
                q++;
            }
        }
        if (o < k / 2) {
            ll diff = k / 2 - o;
            if(q < diff){
                correct = false;
            }
        } else if (o > k / 2) {
            correct = false;
        }
 
        if (correct)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
