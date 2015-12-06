#   euler solution 301
#   answer = # of bianry strings of length 30 that do not have consecutive 1s
#   answer = fib(32) = 2178309

n = 32;
fib = [0, 1];
for i in range(2, 33):
    fib.append(int(fib[i - 1]) + int(fib[i - 2]));
print fib[32];
