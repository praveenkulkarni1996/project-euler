"""
    Let x(n) be the expectation of an n bit string.
    x(0) = 1
    x(i) = sum ( c(i, j) * x(j)) for j = [0 ... i - 1]
    answer = x(32)
"""
import decimal
n = 32
c = [1] * (n + 1);
x = [decimal.Decimal(0)] * (n + 1)
x[0] = 1

for i in xrange(1, n + 1):
    for j in xrange(0, i):
        x[i] += c[j] * x[j]
    x[i] = (x[i] / ((2**i) - 1)) + 1
    for j in xrange(i, 0, -1):
        c[j] += c[j - 1]

print "answer = ", str(x[n])[:12] 
