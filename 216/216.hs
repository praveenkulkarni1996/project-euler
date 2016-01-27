import Math.NumberTheory.Primes.Testing
main = print (length [x | x <- [2..50000000], isPrime((2*x*x) - 1)])
