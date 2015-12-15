import decimal
decimal.getcontext().prec = 105

def count(string):
    num = 0
    for digit in string:
        num += int(digit)
    return num

answer = 0
for i in range(2, 100):
    if i in [4, 9, 16, 25, 36, 49, 64, 81] : continue
    answer += count(str((decimal.Decimal(i).sqrt()) / decimal.Decimal(10))[2:102])
print answer
