def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

n = 100
a = [2]
for i in xrange(1, 34):
    a += [1, 2*i, 1]

while len(a) > n: a.pop()
x = 1
y = a[-1]
a.pop()
while len(a) >= 1:
    A = a[-1]
    a.pop()
    x, y = (A*x) + y, x

count = 0
d = gcd(x, y)
for digit in str(x / gcd(x, y)):
    count += int(digit)
print count 
