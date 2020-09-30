#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

struct node {
    int cnt;
    map<int, int> adj;

    node() {
        cnt = 0;
    }
};

long long ans = 0;
int last_node = 0;
node t[5000005];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';

        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }
        cur = t[cur].adj[ch];
    }
    if(t[cur].cnt == 0)
        ans++;
    t[cur].cnt++;

}


int main() {
    ios_base::sync_with_stdio(0);


    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        add(s);

    }
    cout << ans << "\n";
}
