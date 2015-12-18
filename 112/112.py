count = 0
i = 1
while True:
    x = str(i)
    y = "".join(sorted(str(x)))
    if (x == y or x == y[::-1]):
        count += 1
    if count * 100 == i :
        print i
        break
    i += 1
