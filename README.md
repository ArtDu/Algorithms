### Различные алгоритмы для личного пользования

for speed:  
```bash
g++ a.cpp -o a -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result
```
  
for test:
```bash
g++ a.cpp -o a -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
```  

![Comparsion of difficults](img/difficult_cmp.png)


policy based data structures
```c++
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using namespace __gnu_pbds;
//less = set
typedef tree<ll,null_type,less<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
//less_equal = multiset
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_multiset;

ll idx = s.order_of_key(key);
auto it = s.find_by_order(idx);
cout << idx << " " << *it << "\n";
```

standart template
```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define vec vector
#define P pair
#define F first
#define S second
#define MAXX 1e15
#define MOD 1e9 + 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) {
        
    }
    
    return 0;
}
```

freopen
```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

количество единиц в двоичном представлении;
```c++
__builtin_popcount(x)
```

setprecision + fixed
```c++
double root = 1.4454568;
cout << fixed; // use fixed point format
cout << setprecision( 3 ) << root << endl;
```

setwidth
```c++
cout << setw( 10 ) << setfill( '*' ) << x << endl;
```