for i in range (1, 10000000):
    string = "".join(sorted(str(2 * i)));
    ans = True
    for x in range (3, 7):
        if string != "".join(sorted(str(x * i))):
            ans = False
            break
    if ans:
        print i
        break
