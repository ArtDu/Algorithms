#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1000;

int n;
vector<int> permutation;
bool chosen[MAXX];
void search() {

    if(permutation.size() == n) {
        for(auto &i : permutation) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();

            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    n = 3;
    //from 1 to 3 included
    search();

    return 0;
}