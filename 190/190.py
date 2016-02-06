from decimal import Decimal

answer = 0
for m in xrange(2, 15 + 1):
    c = 2 / (Decimal(m) + 1)
    p = Decimal(1)
    for i in xrange(1, m + 1):
        x = i * c
        p *= pow(x, i)
    answer += int(p)
print answer
""" used lagrange multipliers, 
    proved that x_i = (2 * i)/(m + 1) 
"""
