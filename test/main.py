from datetime import datetime, timedelta

t = input()
start, end = input().split()

start = datetime.strptime(start, "%Y-%m-%d")
end = datetime.strptime(end, "%Y-%m-%d")

ans = []
n = (end - start).days
last = start
for i in range(1, n + 1):
    new_d = start + timedelta(i)
    if (t == "WEEK" and new_d.weekday() == 0) or \
            (t == "MONTH" and new_d.month != last.month) or \
            (t == "QUARTER" and new_d.month != last.month and new_d.month in {1, 4, 7, 10}) or \
            (t == "YEAR" and new_d.year != last.year) or \
            (t == "FRIDAY_THE_13TH" and new_d.weekday() == 4 and new_d.day == 13):
        tmp = (new_d - timedelta(1))
        ans.append((last, tmp))

        last = new_d

ans.append((last, end))

print(len(ans))
for start, end in ans:
    print(f'{start.strftime("%Y-%m-%d")} {end.strftime("%Y-%m-%d")}')
