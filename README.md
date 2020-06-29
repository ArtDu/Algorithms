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

standart template
```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXX = 1e9;

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