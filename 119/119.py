def digits(number):
    digit = []
    while number > 0:
        digit.append(number % 10)
        number = number // 10
    return digit

a = []
N = 10**16

for i in range(2, 150):
    num = i;
    while (num < N):
        if(sum(digits(num)) == i):
            if num not in a: 
                a.append(num)
        num *= i
a.sort();

print a[8:][30 - 1]
