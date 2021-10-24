inner_str = input()

# initialize two-dimensional list
count = [
    [
        0 for _ in range(len(inner_str))
    ] for _ in range(len(inner_str))
]

def get_count_aux(l, r):
    if l == r:
        return 1
    elif l > r:
        return 0

    if count[l][r] != 0:
        return count[l][r]

    if inner_str[l] == inner_str[r]:
        ans = get_count_aux(l + 1, r) + get_count_aux(l, r - 1) + 1
    else:
        ans = get_count_aux(l + 1, r) + get_count_aux(l, r - 1) \
              - get_count_aux(l + 1, r - 1)

    count[l][r] = ans
    return ans


def get_count():
    return get_count_aux(0, len(inner_str) - 1)



print(get_count())
