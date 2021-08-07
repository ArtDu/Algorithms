// x.pdf -- i problem
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
 
int cnt[N], s[N];
set<int>st[N];
 
int main() {
    int n, m, q, x, y, op;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= q; ++i) {
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1) st[x].insert(y), s[x] -= cnt[y];
        else if(op == 2) st[x].erase(y), s[x] += cnt[y];
        else cnt[y]++, s[x]--;
    }
    for(int i = 1; i <= m; ++i) {
        for(set<int>::iterator it = st[i].begin(); it != st[i].end(); ++it)
            s[i] += cnt[*it];
        printf("%d\n", s[i]);
    }
    return 0;
}
