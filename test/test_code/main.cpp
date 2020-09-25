#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void genrator (set<string> &vocab, vector<string> &rules, ll n, ll m) {
    ll cnt = 0;
    while (1) {
        auto iter = vocab.begin();
        for (int i = 0; i < cnt - 1; ++i) {
            iter++;
        }
        ll size = vocab.size();
        while (iter != vocab.end()) {
            for (int i = 0; i < m; ++i) {
                string new_str;
                for (int j = 0; j < n; ++j) {
                    if (rules[i][j] != '-') {
                        new_str += rules[i][j];
                    } else {
                        new_str += (*iter)[j];
                    }
                }
                vocab.insert(new_str);
            }
            iter++;
        }
        if ((ll)(vocab.size()) == size)
            break;
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    set<string> vocab;
    string s;
    cin >> s;
    vocab.insert(s);
    vector<string> rules(m);
    for (int i = 0; i < m; ++i) {
        cin >> rules[i];
    }
    genrator(vocab, rules, n, m);
    ll t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (vocab.find(str) == vocab.end())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}