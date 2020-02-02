#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {

    int n, el;
    cin >> n;

    vector<ll> prefix(n);
    for (int i = 0; i < n; ++i) {
        cin >> el;
        if (i == 0) {
            prefix[i] = el;
        } else {
            prefix[i] = prefix[i - 1] + el;
        }
    }



//    for (int j = 0; j < n; ++j) {
//        cout << prefix[j] << " ";
//    }
//    cout << endl;



    return 0;
}
