A = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
B = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
X = [(127 + 19*n)*(7**n) for n in xrange(0, 18)]
fib = [100, 100]
answer = ""
for i in xrange(2, 80):
    fib.append(fib[-1] + fib[-2]);

def g(n, p):
    if(n == 0): return A[p - 1]
    elif(n == 1): return B[p - 1]
    else: 
        if(p <= fib[n - 2]) : return g(n - 2, p)
        else                : return g(n - 1, p - fib[n - 2])

for p in X:
    for i in xrange(len(fib)):
        if fib[i] >= p:
            answer += str(g(i, p))
            break
print answer[::-1]
