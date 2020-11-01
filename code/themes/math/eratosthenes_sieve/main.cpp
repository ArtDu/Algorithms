//http://codeforces.com/gym/300780/problem/K
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
using ll = long long;
using ld = long double;
const ll MAXX = 1e15;
const ll MOD = 1e9 + 7;
 
//less = set
typedef tree<ll,null_type,less<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
//less_equal = multiset
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_multiset;
 
 
#define P pair
#define F first
#define S second
#define vec vector
#define pb push_back
#define LOWER 0
#define UPPER 1
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
 
    ll n = 4 * 1e7;
    vector<int> is_prime(n+5, -1);
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] == -1) {
            for (ll j = i + i; j <= n; j += i)
                if(is_prime[j] == -1)
                    is_prime[j] = 1;
                else
                    is_prime[j]++;
        }
    }
    ll t, x;
    cin >> t;
    while(t--){
        cin >> x;
        if(is_prime[x] == -1){
            cout << "Prime\n";
        } else {
            cout << is_prime[x] << "\n";
        }
    }
    return 0;
}
