r = [0, 0, 0, 1]
b = [1, 1, 1, 1]

for i in range (4, 51):
    b.append(b[i - 1] + r[i - 1])
    add = 0
    for j in range(0, i - 2):   add += b[j]
    r.append(add)
print r[50] + b[50]
