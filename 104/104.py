def pandigital(num):
    return ("".join(sorted(num)[::-1]) == "987654321")

f = [[1, 1], [1, 0]]

a, b, i = 1, 0, 1

def mul(A, B):
    return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0]), (A[0][0]*B[0][1] + A[0][1]*B[1][1])],
           [(A[1][0]*B[0][0] + A[1][1]*B[1][0]), (A[1][0]*B[0][1] + A[1][1]*B[1][1])]]


def mpow(A, n):
    x = [[1, 0], [0, 1]]
    y = A
    N = n 
    while N > 0 :
        if N & 1 ==  1:
            x = mul(x, y)
        y = mul(y, y)
        N >>= 1
    return x

a = 1
b = 0
N = 1000000000
while True :
    a, b, i = (a + b) % N, a, i + 1
    if(pandigital(str(a)[-9:])): 
        if (pandigital( str(mpow(f, i)[0][1])[:9])):
            print i
            break
