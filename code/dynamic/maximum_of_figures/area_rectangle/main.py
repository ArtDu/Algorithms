def max_area_histogram(hist):
    stack = list()
    i = 0
    max_area = 0
    while i < len(hist):
        if (not stack) or (hist[i] >= hist[stack[-1]]):
            stack.append(i)
            i += 1
        else:
            top = stack.pop()

            if not stack:
                area = hist[top] * i
            else:
                area = hist[top] * (i - 1 - stack[-1])

            max_area = max(area, max_area)

    while stack:
        top = stack.pop()

        if not stack:
            area = hist[top] * i
        else:
            area = hist[top] * (i - 1 - stack[-1])

        max_area = max(area, max_area)

    return max_area


def max_area_rectangle(rec):
    if not rec:
        return 0

    result = max_area_histogram(rec[0])

    for i in range(1, len(rec)):
        for j in range(len(rec[i])):
            if rec[i][j] == 1:
                rec[i][j] += rec[i - 1][j]
        result = max(result, max_area_histogram(rec[i]))

    return result