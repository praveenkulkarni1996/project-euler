from itertools import permutations 
a = map(str, range(1, 10));
b = list(permutations(a));
c = set()

for perm in b :
    perm_s = "".join(perm)
    for i in xrange (1, 5):
        num1 = int(perm_s[0: i])
        num2 = int(perm_s[i: 5])
        num3 = int(perm_s[5: ])
        if num1 * num2 == num3:
            #print num1 , num2 , num3        
            c.add(num3)
    
print sum(list(set(c)))
