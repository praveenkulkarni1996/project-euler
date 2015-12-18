def funct(g):
    x = 1
    for i in xrange(0,9):
            x *= (g + i + 1)
    for i in xrange(0,9):
        x /= (i + 1)
    return x

count = 0
n = 100
for i in xrange(1, n + 1):
    count += funct(i) - 10;
count += funct(n)
print count - 1
