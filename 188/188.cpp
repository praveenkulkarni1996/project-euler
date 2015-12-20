#include <cstdio>

//  used to calculate etf(10 ^ x) and their descendants
//  if n is divisible by 10 then etf(n) = 2n/5
//  else n is only divisible by 2 then etf(n) = n / 2
int etf(int n) {
    if (n % 5 == 0)         return (n << 1) / 5;
    return n >> 1;
}

//  calculates a ^ b mod c
int modulo(int a, int b, int c){
    long long x = 1, y = a; 
    while(b) {
        if(b & 1)
            x = (x * y) % c;
        y = (y * y) % c;
        b >>= 1;
    }
    return x % c;
}

long long tetration(long long base, long long expo, long long modu) {
    if (expo == 1)      return base;
    else if (etf(modu) > 2)  return modulo(base, tetration(base, expo - 1, etf(modu)), modu);
    else if (etf(modu) == 2 && (base & 1) == 1) return base;
    else if (etf(modu) == 2 && (base & 1) == 0) return 1;
    return 1;
}

int main() {
    int x = 1e8;
    printf("%lld\n", tetration(1777, 1855, 1e8));
}
