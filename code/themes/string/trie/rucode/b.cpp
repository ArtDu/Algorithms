#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define pb push_back

struct node {
    int cnt_node_and_childs;
    int cnt_node;
    int idx;
    map<char, int> adj;

    node() {
        cnt_node_and_childs = 0;
        cnt_node = 0;
        idx = -1;
    }
};

int k;
int ans;
int last_node = 0;
int last_idx = 0;
node t[5000005];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }
        t[cur].cnt_node_and_childs++;
        cur = t[cur].adj[ch];
    }
    t[cur].cnt_node++;
    t[cur].cnt_node_and_childs++;
    t[cur].idx = last_idx++;
}


//сначала отнимаем из вершины, потом из детей слева направо
void _find(int cur) {
    k -= t[cur].cnt_node;
    if(k <= 0) {
        ans = t[cur].idx;
        return;
    }

    int w = 0;
    for (auto &[key, v] : t[cur].adj) {
        if(ans != -1) return;
        if(t[v].cnt_node_and_childs + w < k){
            w += t[v].cnt_node_and_childs;
        } else {
            k -= w;
            _find(v);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(isdigit(s[0])){
            k = stoi(s);
            ans = -1;
            _find(0);
            cout << strs[ans] << "\n";
        } else {
            strs.pb(s);
            add(s);
        }
    }
    return 0;
}


