from random import *

if __name__ == '__main__':

    for i in range(1):
        n = 10
        k = 4
        name = str(i)
        file = open('tests/' + name + '.t', 'w')
        file.write(f"{n} {k}\n")
        s = set()
        while True:
            a = randint(1, 50)
            s.add(a)
            if len(s) == n:
                break

        l = list(s)
        l.sort()
        for i in l:
            file.write(f"{i} ")
        file.write(f"\n")

        file.close()
