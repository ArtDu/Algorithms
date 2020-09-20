#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct seg{
    ll b, e, i;
    seg() : b(0), e(0), i(0) {}
    seg(ll b, ll e, ll i) : b(b), e(e), i(i){}
    bool operator<(seg& o){
        return make_tuple(b, e, i) < make_tuple(o.b, o.e, o.i);
    }
};

ll n, b, e, d;
vector<seg> s;
vector<ll> begins;

vector<ll> coverage;
vector<bool> take;
vector<ll> nextItem;


ll next(ll i) {
    ll e = s[i].e;
    auto it = upper_bound(begins.begin() + i + 1, begins.end(), e);
    if (it != begins.end())
        return it - begins.begin();
    return n;
}

void solve() {
    coverage[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        ll next_ = next(i);
        if (s[i].e - s[i].b + 1 + coverage[next_] > coverage[i + 1]) {
            coverage[i] = s[i].e - s[i].b + 1 + coverage[next_];
            take[i] = true;
            nextItem[i] = next_;
        } else {
            coverage[i] = coverage[i + 1];
            nextItem[i] = i + 1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n;

    s.resize(n);
    begins.resize(n);
    take.resize(n);
    nextItem.resize(n);
    // for n case
    coverage.resize(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> b >> d;
        e = b + d - 1;

        s[i] = seg(b, e, i);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        begins[i] = s[i].b;
    }
    solve();

    cout << coverage[0] << "\n";
    ll i = 0;
    while (i != n) {
        if (take[i])
            cout << s[i].i << " ";
        i = nextItem[i];
    }
    cout << "\n";
    return 0;
}