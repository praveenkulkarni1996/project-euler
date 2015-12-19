def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

num, denom = 1, 1
for i in range(1, 10):
    for j in range(i + 1, 10):
        for k in range(1, 10):
            if (10 * i + k) * j == i * (10*k + j):
                num *= i
                denom *= j
print denom / gcd(num, denom)
