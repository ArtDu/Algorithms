//https://stepik.org/lesson/307318/step/2?unit=289406w

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m, k, cnt, l, r, mid;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        k--;
        cnt = 0;
        l = -1, r = n;
        while(l + 1 < r) {
            mid = l + (r - l) / 2;
            cnt++;
            if(mid <= k) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}