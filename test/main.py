from math import log2, ceil


def get_degree(N):
    return ceil(log2(N))


print(get_degree(200))
