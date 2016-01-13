print abs(sum(x * x for x in xrange(1, 101)) - sum(x for x in xrange(1, 101)) ** 2)
