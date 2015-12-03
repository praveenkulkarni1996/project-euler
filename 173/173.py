#	Using up to one million tiles how many different "hollow" square laminae can be formed?
#	Problem 173
#	Ans = 1572729	

import math

M = 1000000
def count(k) :
	return int(math.sqrt(M + (k*k)) - k) / 2; 

sum = 0;
for i in range(1, M):
	sum += count(i)

print sum