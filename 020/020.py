""" Print the sum of digits in 100!
    This is a very easy question , 
    I choose to learn python functional programming features from this
    I have used reduce(x, y, z)
        x is a binary operator that returns a value
        y is an iterable object (list, generator .... )
        z is the starting value.
    For example x = mul
    y = [10, 20, 30]
    z = 1
    reduce(x, y, z) = (((1 * 10) * 20) * 30)  
    sum is short for reduce(add, y, 0)
"""
from operator import mul 
print sum(int(z) for z in str(reduce (mul , xrange(1, 101), 1)))
