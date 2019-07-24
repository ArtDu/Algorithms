##### Правую часть режем, левую оставляем

if n == 0:
    q = 0

if n > 0:
    i = 1 ... n
    q = max(q, p[i] + dp(p, mem, n - i))
 
mem[n] = q
return q

