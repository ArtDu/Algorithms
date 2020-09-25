import random
import string

if __name__ == '__main__':
    alpha = 'abc'

    for i in range(1, 5):
        n = random.randint(3, 8)
        m = random.randint(5, 10)
        name = str(i)
        file = open('tests/' + name + '.t','w')
        pattern = ''
        for i in range(0, n):
            pattern += random.choice(alpha)
        file.write(f"{n} {m}\n")
        file.write(f"{pattern}\n")
        my_set = set()
        for i in range(0, m):
            rule = ''
            for j in range(0, n):
                monet = random.randint(1, 2)
                if monet == 1:
                    c = random.choice(alpha)
                    rule += c
                else:
                    c = '-'
                    rule += c
                if (c != '-'):
                    my_set.add(c)

            file.write(f"{rule}\n")

        k = random.randint(10, 20)
        file.write(f"{k}\n")
        vocab = ''
        for each in my_set:
            vocab += each
        for i in range(0, k):
            str_to_check = ''
            for j in range(0, n):
                str_to_check += random.choice(vocab)
            file.write(f"{str_to_check}\n")

        file.close()
