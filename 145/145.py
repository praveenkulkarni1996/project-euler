#output:
#608720
#4658.87864995 seconds
import time

t = time.time()

l = [1,3,5,7,9]

i , j = 1, 10
count = 0
while i < 1000000000 :
    answer = True
    if i == j :
        j += 10
        i += 1
        continue
    for ch in str(i + int(str(i)[::-1])) :
        if int(ch) not in l :
            answer = False
            break
    if answer :
        count += 1
    i += 1

print count
print time.time() - t , ' seconds'
