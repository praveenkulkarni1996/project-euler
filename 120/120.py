rsum = 0
for x in range(3, 1001):
    r = 2
    for i in range(1, 2 * x):
        r = max(r, ((2*i + 1) * 2 * x) % (x * x))
    rsum += r
print rsum
