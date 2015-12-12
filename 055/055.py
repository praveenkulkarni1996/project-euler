def ispalin(string):
    length = len(string)
    for i in range(0, length / 2):
        if string[i] != string[length - 1 - i] :
            return False
    return True

count = 0
for i in range(1, 10001):
    x, lychrel = i, True
    for iterations in range(1, 51):
        x = x + int(str(x)[::-1])
        if(ispalin(str(x))):
            lychrel = False
            break
    if lychrel : count += 1 
print count
