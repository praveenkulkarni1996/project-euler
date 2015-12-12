count = 0
for a in range(1, 10):
    for b in range (1, 30):
        if b == len(str(a**b)): 
            count += 1
print count
