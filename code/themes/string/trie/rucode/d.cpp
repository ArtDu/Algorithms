#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define pb push_back

struct node {
    
    int cnt_node;
    map<char, int> adj;

    node() {
        cnt_node = 0;
    }
};

int last_node = 0;
node t[5000005];
vector<string> words;

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }

        cur = t[cur].adj[ch];
    }
    t[cur].cnt_node++;
}

ll _find(int idx, int start, int end) {
    int cur = 0;
    for (int i = start; i < end; i++) {
        char ch = words[idx][i];
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            return 0;
        }
        cur = t[cur].adj[ch];
    }
    return t[cur].cnt_node;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        add(words[i]);
    }
    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        for (int j = 1; j < words[i].size(); ++j) {
            int x = _find(i, 0, j);
            int y = _find(i, j, words[i].size());
            ans += x * y;
        }
        cout << ans << "\n";

    }
    return 0;
}


