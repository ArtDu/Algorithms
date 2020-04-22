// based on problem
// https://codeforces.com/gym/100166/attachments

#include <bits/stdc++.h>

using namespace std;

long long d[105][105];
long long aMat[105][105];

void floyd(int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = aMat[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {

    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> aMat[i][j];
        }
    }
    floyd(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

