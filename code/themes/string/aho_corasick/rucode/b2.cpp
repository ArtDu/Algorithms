#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

struct node {
    int par;
    int ch;
    int adj[2];
    int go[2];
    int link;
    int dp;
    int cnt;
    int idx;

    node() {
        idx = -1;
        par = -1;
        ch = -1;
        dp = -1;
        cnt = 0;
        link = -1;
        for (int i = 0; i < 2; i++) {
            adj[i] = go[i] = -1;
        }
    }
};

node t[321321];
bool visited[321321], path[321321];
bool flag;


int link(int x);

int go(int x, int c) {
    if (t[x].go[c] != -1) {
        return t[x].go[c];
    } else if (t[x].adj[c] != -1) {
        return t[x].go[c] = t[x].adj[c];
    } else {
        if (x == 0) {
            return t[x].go[c] = 0;
        }
        return t[x].go[c] = go(link(x), c);
    }
}

int link(int x) {
    if (t[x].link != -1) {
        return t[x].link;
    } else if (x == 0 || t[x].par == 0) {
        return t[x].link = 0;
    } else {
        return t[x].link = go(link(t[x].par), t[x].ch);
    }
}


int dp(int x) {
    if (t[x].dp != -1) {
        return t[x].dp;
    } else {
        return t[x].dp = t[x].cnt + (x == 0 ? 0 : dp(link(x)));
    }
}

int last_node;
int last_idx;

void add(string s) {
    int cur = 0;
    //cout << s << "\n";
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - '0';
        //cout << cur << " " << ch << "\n";
        if (t[cur].adj[ch] == -1) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
            t[last_node].par = cur;
            t[last_node].ch = ch;
        }
        cur = t[cur].adj[ch];
    }
    t[cur].idx = last_idx++;
    t[cur].cnt += 1;
}


void dfs(int cur) {
    //пометить плохие вершины.
    //пройтись по хорошим по циклу.
    int bad = dp(cur);
    if (bad)
        return;

    if (path[cur]) {
        flag = true;
        return;
    }

    if (visited[cur])
        return;

    visited[cur] = true;

    path[cur] = true;
    dfs(go(cur, 0));
    dfs(go(cur, 1));
    path[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }

    dfs(0);
    if (flag) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }
    return 0;
}
