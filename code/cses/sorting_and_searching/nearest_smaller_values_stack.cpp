#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define P pair
#define F first
#define S second
#define MAXX 1e15

using ll = long long;

ll n, x;
stack<P<ll,ll>> st;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while(!st.empty() && st.top().F >= x){
            st.pop();
        }
        if(st.empty()){
            cout << "0 ";
        } else {
            cout << st.top().S << " ";
        }
        st.push({x, i});
    }
    cout << "\n";
    return 0;
}
