""" answer = 3857447
    takes about 5-10 minutes to run
"""
from fractions import Fraction
n = 18
a = [set() for x in xrange(n + 1)]
a[1] |= set([Fraction(1,1)])
print a

for i in xrange(2, 1 + n):
    for j in xrange(1, i):
        k = i - j
        if k < j :break
        for x in a[j]:
            for y in a[k]:
                a[i].add(Fraction(x) + Fraction(y))
                a[i].add(Fraction(x * y, x + y))
b = set([])
for seta in a: b |= seta
print "answer =", len(b)
