# This is the brilliance of functional programming
# I could also have taken mod 1e10
""" I have to take the last 10 digits of number = sum {x^x | 1 <= x <= 1000} """
print str(sum(x ** x for x in xrange(1, 1001)))[-10:]
