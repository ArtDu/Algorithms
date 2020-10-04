#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define vec vector
#define P pair
#define FI first
#define SE second
#define pb push_back

using ll = long long;
const ll MAXX = 1e15;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, S;
    cin >> N >> S;
    vec<ll> v(N + 5);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }


    vec<vec<ll>> dp(N + 5, vec<ll>(S + 5));
    vec<vec<P<ll,ll>>> prev(N + 5, vec<P<ll,ll>>(S + 5));
    ll mx = 0;
    P<ll,ll> mx_idx = {-1,-1};
    for (int i = 1; i <= N; ++i) {
        for (int s = 1; s <= S; ++s) {
            for (int j = 0; j < i; ++j) {
                if(s - v[i] >= 0 && v[i] >= v[j]){
                    if(dp[j][s - v[i]] + 1 > dp[i][s]){
                        dp[i][s] = dp[j][s - v[i]] + 1;
                        prev[i][s] = {j, s - v[i]};
                    }
                }
            }
            if(dp[i][s] > mx){
                mx = dp[i][s];
                mx_idx = {i, s};
            }
        }
    }
    cout << mx << "\n";
    vec<bool> used(N + 5);
    while(mx_idx.FI != 0){
        used[mx_idx.FI] = true;
        mx_idx = prev[mx_idx.FI][mx_idx.SE];
    }
    for(int i = 1; i <= N; ++i)
        cout << used[i] << " ";
    cout << "\n";
    return 0;
}

