from math import sqrt

count = 0
n = 2000
m = 1000000
for i in xrange(1, n + 1):
    print i
    for j in xrange(1, i + 1):
        for k in xrange(1, j + 1):
            x = sqrt(i**2 + (j + k)**2);
            if(x == int(x)):
                count += 1
                if(count >= m):
                    print i
                    exit()
