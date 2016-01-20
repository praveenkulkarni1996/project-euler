from decimal import Decimal 

def gcd(a, b):
    while(b): a, b = b, a % b
    return a

def term(a, b):
    b = b / gcd(a, b)
    while(b % 2 == 0): b /= 2
    while(b % 5 == 0): b /= 5
    return b == 1

best = 1;
answer = 0
for num in xrange(1, 10000 + 1):
    r = Decimal(num) / Decimal(best)
    opt = pow(r, best)
    r = Decimal(num) / Decimal(best + 1)
    if(pow(r, best + 1) > opt):
        best += 1
    if(5 <= num <= 10000):
        if(term(num, best)) : answer -= num
        else: answer += num
print answer
