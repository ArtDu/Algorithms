/*
 * take or not
 * O(2^n)
 *
 *                              {1,2,3}
 *                    search(3)
 *                              {1,2}
 *           search(2)
 *                              {1,3}
 *                    search(3)
 *                              {1}
 * search(1)
 *                              {2,3}
 *                    search(3)
 *                              {2}
 *           search(2)
 *                              {3}
 *                    search(3)
 *                              {}
 * */


#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> subset;
void search(int k) {

    if(k == n+1) {
        for(auto &i : subset) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    n = 5;
    //from 3 to 5 included
    search(3);

    return 0;
}