print max(sum(int(z) for z in str(num)) for num in (a**b for a in xrange(1, 101) for b in xrange(1, 101))) 
