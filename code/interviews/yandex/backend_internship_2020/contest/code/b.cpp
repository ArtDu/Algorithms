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


    ll n, t, m;
    cin >> n;
    vec<vec<ll>> v(n);
    vec<ll> vi_max(n);
    vec<ll> vi_min(n);

    ll mnT = 0, mxT = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        v[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
        if (m % 2 == 0) {
            mnT += v[i][m / 2 - 1];
            mxT += v[i][m / 2];
            vi_min[i] = v[i][m / 2 - 1];
        } else {
            mnT += v[i][m / 2];
            mxT += v[i][m / 2];
            vi_min[i] = v[i][m / 2];
        }
        vi_max[i] = v[i][m / 2];
    }
    cin >> t;
    if(n == 1){
        cout << t << "\n";
        return 0;
    }

    if (mnT <= t && t <= mxT) {
//        cout << "1\n";
        ll diff = t - mnT;
        for (int i = 0; i < n; ++i) {
            ll max_mid = v[i][v[i].size() / 2];
            if (v[i].size() % 2 == 0) {
                ll min_mid = v[i][v[i].size() / 2 - 1];
                ll d = max_mid - min_mid;
                if (diff) {
                    if(d <= diff){
                        diff -= d;
                        cout << max_mid << " ";
                    } else {
                        cout << min_mid + diff;
                        diff = 0;
                    }
                } else {
                    cout << min_mid << " ";
                }
            } else {
                cout << max_mid << " ";
            }
        }
        cout << "\n";
    } else if (t < mnT) {
//        cout << "2\n";
        ll diff = mnT - t;

        for (int i = 0; i < diff; ++i) {
            vec<P<ll,ll>> sums;
            for (int j = 0; j < n; ++j) {
                ll old_mid = vi_min[j];
                if(old_mid == 0) continue;
                ll mid = vi_min[j] - 1;
                ll s = 0;
                for (int k = 0; k < v[j].size(); ++k) {
                    s += abs(v[j][k] - mid);
                }
                sums.pb({s, j});
            }
            sort(sums.begin(), sums.end());
            vi_min[sums[0].S]--;
        }

        for (int i = 0; i < n; ++i) {
            cout << vi_min[i] << " ";
        }
        cout << "\n";
    } else if (t > mxT) {
//        cout << "3\n";
        ll diff = t - mxT;

        for (int i = 0; i < diff; ++i) {
            vec<P<ll,ll>> sums(n);
            for (int j = 0; j < n; ++j) {
                ll mid = vi_max[j] + 1;
                ll s = 0;
                for (int k = 0; k < v[j].size(); ++k) {
                    s += abs(v[j][k] - mid);
                }
                sums[j] = {s, j};
            }
            sort(sums.begin(), sums.end());
            vi_max[sums[0].S]++;
        }

        for (int i = 0; i < n; ++i) {
            cout << vi_max[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}