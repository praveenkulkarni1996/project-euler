count = dict()
ans = dict()
for i in range(0, 100000):
    x = i ** 3
    z = int(''.join(sorted(str(x), reverse = True)))
    if(z in count.keys()) : count[z] += 1
    else : count[z] = 1
    if (count[z] == 1) : ans[z] = x
    elif (count[z] == 5) : print ans[z]; break
