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

int ans = 0;
int last_node = 0;
node t[5000005];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }

        if(t[cur].cnt_node == 0 && cur != 0){
            ans++;
        }
        t[cur].cnt_node++;

        cur = t[cur].adj[ch];
    }
    if(t[cur].cnt_node == 0){
        ans++;
    }
    t[cur].cnt_node++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    for (int sz = 1; sz <= s.size(); ++sz) {
        add(s.substr(s.size() - sz));
        //cout << s.substr(s.size() - sz) << "\n";
    }
    cout << ans << "\n";
    return 0;
}


