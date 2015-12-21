#include <cstdio>
using namespace std;

const int n = 5e8 + 1;
int etf[n];

//  this calculates the euler totient function from 1 to n
void sieve() {
    for(int i = 0; i < n ; ++i) etf[i] = i;
    for(int i = 2; i < n ; ++i) if(etf[i] == i) {
        for(int j = i; j < n; j += i) {
            etf[j] /= i;
            etf[j] *= i - 1;
        }
    }
}
//  this caluculates the a^b mod c
inline int modulo(const int a, int b, const int c) {
    long long x = 1, y = a; 
    while(b > 0){
        if(b & 1)
            x = (x * y) % c;
        y = (y * y) % c;
        b >>= 1;
    }
    return x % c;
}

long long g = 0;
long long f = 0;

//  f[x] = etf[n] + etf[n^2] + ... + etf[n ^ n]    mod n + 1
//  f[x] = etf[n] * (1 + n + n^2 + .... n^(n-1))   mod n + 1
//  f[x] = etf[n] * (0) mod n + 1 if n is even
//  f[x] = etf[n] * n^(n-1) if n is odd
//  g[x] = sum of f[y] where y is odd number <= x
//  this code takes a while to run, about a minute i think

int main() {
    sieve();
    for(int i = 1; i < n; i += 2) {
       f = modulo(i, (i - 1) % etf[i + 1] , i + 1);
       f = (f * etf[i])  % (i + 1);
       g += f;
    }   
    printf("%lld\n", g);
}
