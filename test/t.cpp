#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
    vector<Node *> child;
    ll cnt;

    Node() : cnt(0) { child.resize(26, nullptr); }
};

Node *trie = new Node;

void insert(string &s, vector<vector<char>> &charTable) {
    Node *cur;
    ll c;
    queue<Node*> lists;
    lists.push(trie);
    for (int i = 0; i < s.size(); ++i) {
        queue<Node*> q;
        while(!lists.empty()){
            cur = lists.front();
            lists.pop();
            if(s[i]=='-'){
                for(auto &j : charTable[i]){
                    c = j - 'a';
                    if (cur->child[c] == nullptr) {
                        cur->child[c] = new Node;
                    }
                    q.push(cur->child[c]);
                }
            } else{
                c = s[i] - 'a';
                if (cur->child[c] == nullptr) {
                    cur->child[c] = new Node;
                }
                q.push(cur->child[c]);
            }
        }
        lists=q;
    }
}

vector<vector<char>> getCharTable(vector<string> &rules) {
    vector<vector<char>> out (rules.size());
    for (auto & rule : rules) {
        for (int j = 0; j < rule.size(); ++j) {
            if (rule[j] != '-')
                out[j].push_back(rule[j]);
        }
    }
    return out;
}

void getTrie(vector<string> &rules) {
    vector<vector<char>> charTable = getCharTable(rules); // Table of all chars instead '-' for each column
    for (auto &j : rules) {
        insert(j, charTable);
    }
//    ll c;
//    for (auto &j : rules) {
//        Node *cur = trie;
//        ll index = 0;
//        for (char symb : j) {
//            if (symb != '-') { // Simple char insert
//                c = symb - 'a';
//                if (cur->child[c] == nullptr) {
//                    cur->child[c] = new Node;
//                }
//            } else {
//                for (auto k : charTable[index]) { // Inserting all found chars like kids of previous
//                    c = k - 'a';
//                    if (cur->child[c] == nullptr) {
//                        cur->child[c] = new Node;
//                    }
//                }
//            }
//            cur = cur->child[c];
//            index++;
//        }
//        cur->cnt++;
//    }
}

bool compare(string &pattern) {
    Node *cur = trie;
    ll c;
    for (char i : pattern) {
        c = i - 'a';
        if (cur->child[c] == nullptr)
            break;
        cur = cur->child[c];
        if (i == pattern.back())
            return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    string s;
    vector<string> rules(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        cin >> s;
        rules[i] = s;
    }
    getTrie(rules);

    ll t;
    cin >> t;
    while (t--) {
        string pattern;
        cin >> pattern;
        if (compare(pattern))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}