nmax = 0
for a in range(1, 101):
    for b in range(1, 101):
        x = a ** b;
        n = 0
        for c in str(x): n += int(c)
        if n > nmax : nmax = n
print nmax
