#include <iostream>
#include <cstdio>
#include <ctime>
const int n = 250250; const int mod = 250;
const int m = 28203715;
const unsigned long long md = (unsigned long long) 1e16;

inline int modpow(int a, int b) {
    long long x = 1, y = a % mod;
    while (b) {
        if(b & 1) x = (x * y) % mod;
        y = (y * y) % mod;
        b >>= 1;
    }
    return x % mod;
}

unsigned long long a[mod], b[mod];
int main() {
    clock_t start = clock();
    a[0] = 1;
    for(int i = 1; i <= n ; ++i) {
        int setnum = modpow(i, i);
        for(int j = 0; j < mod; ++j) {
            int y = (j + setnum);
            while(y >= mod) y -= mod;
            b[y] = a[j];
        }
        for(int j = 0; j < mod; ++j) {
            a[j] += b[j];
            if(a[j] >= md) a[j] -= md;
        }
    }
    printf("%llu\n", a[0] - 1);
    printf("time = %f\n", double(clock() - start) / CLOCKS_PER_SEC);
}

