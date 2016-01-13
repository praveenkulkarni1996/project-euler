def palindrome(x):
    num = str(x)
    length = len(num)
    for i in xrange(length):
        if(num[i] != num[length - 1 - i]): return False
    return True

print max((z for z in [x * y for x in xrange(100, 1000) for y in xrange(x, 1000)] if palindrome(z)))
