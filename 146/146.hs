import Math.NumberTheory.Primes

setx = [x | x <- [10,12 .. 150000000], x `mod` 3 /= 0, x `mod` 7 /= 0, x `mod` 13 /= 0]
euler = sum[y | y <- setx, 
                isPrime(y * y + 1), 
                isPrime(y * y  + 3), 
                isPrime(y * y  + 7), 
                isPrime(y * y  + 9), 
                isPrime(y * y  + 13), 
                isPrime(y * y  + 27),
                not(isPrime(y * y  + 11)), 
                not(isPrime(y * y  + 5)), 
                not(isPrime(y * y  + 15)), 
                not(isPrime(y * y  + 17)), 
                not(isPrime(y * y  + 19)), 
                not(isPrime(y * y  + 21)), 
                not(isPrime(y * y  + 23)), 
                not(isPrime(y * y  + 25))] 
