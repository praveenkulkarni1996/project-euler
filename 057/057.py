n, d, count = 1, 2, 0
for i in xrange(1, 1000 + 1):
    if(len(str(n + d)) > len(str(d))):count += 1
    n, d = d, 2*d + n
print count
