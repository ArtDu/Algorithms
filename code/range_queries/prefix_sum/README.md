### Prefix sum

#### 1 dimensional

```c++
S(a, b) = S(0, b) - S(0, a - 1);
```

![](img/1dim.png)

#### 2 dimensional

```c++
S(A) - S(B) - S(C) + S(D);
```

![](img/2dim.png)