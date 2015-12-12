b = [1] * 51
r = [0] * 50 + [1]
i = 51
while(True): 
    b.append(b[i - 1] + r[i - 1])
    add = 0
    for j in range(0, i - 49): add += b[j]
    r.append(add)
    if r[i] + b[i] > 1000000 :
        print i
        break
    i += 1
