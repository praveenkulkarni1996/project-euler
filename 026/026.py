maxcount = 0
maxnum = 0
for i in xrange(1, 1000):
    a = []
    q = 0
    r = 1
    count = 0
    while r != 0 :
        if r in a : 
            count = len(a) - a.index(r)
            break
        else : 
            a.append(r)
            q, r = divmod(10 * r, i)
    if count > maxcount :
        maxcount = count
        maxnum = i
print maxnum

# ans = 983
                    
    

