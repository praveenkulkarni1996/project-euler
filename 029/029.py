numbers = {}
for a in range(2, 101):
    for b in range(2, 101): 
        if(a ** b not in numbers):
            numbers[a ** b] = 0;
print len(numbers)
