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