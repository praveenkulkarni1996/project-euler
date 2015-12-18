def palindrome(num):
    string = str(num)
    length = len(string)
    for i in xrange(0, length >> 1):
        if string[i] != string[length - 1 - i]: return False
    return True

sqr = [0];
N = 10 ** 8
n = 10 ** 4

for i in xrange(1, n + 1):
    sqr.append(i * i + sqr[-1])

summation = 0
count = 0
answers = []
for i in xrange(0, n + 1):
    for j in xrange(i + 2, n + 1):
        t = sqr[j] - sqr[i]
        if t >= N : break
        elif palindrome(t) and t not in answers:
            answers.append(t)
            count += 1
print sum(answers)
