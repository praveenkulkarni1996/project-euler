n = 800000
prime = [True] * n
prime[0] = prime[1] = False

i = 2;
while i * i < n :
    if prime[i] :
        j = i * i
        while j < n :
            prime[j] = False
            j += i
    i += 1

rprime = [False] * n
lprime = [False] * n
for i in [2, 3, 5 , 7]: lprime[i] = rprime[i] = True

i = 11
while i < n:
    if prime[i] and rprime[i/10] :
        rprime[i] = True;
    i += 1

i = 11
while i < n:
    if prime[i] :
        if lprime[int(str(i)[1:])]:
            lprime[i] = True
    i += 1

count = 0
add = 0
i = 10
while i < n :
    if lprime[i] and rprime[i]:
        count += 1
        add += i
    i += 1
print add
