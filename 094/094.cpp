//  a very brute force solution, takes about 7 seconds to run
//  definitelty take a look at the thread
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>

unsigned long long sum = 0;

inline bool integral_area1(const int x) {
    long double y = sqrtl ((3LL * x + 1) * (x - 1));
    if(y == (long long)(y)) {
        y *= (x + 1);
        y /= 4;
        return (y == floorl(y));
    }
    return false;    
}

inline bool integral_area2(const int x) {
    long double y = sqrtl ((3LL * x - 1) * (x + 1));
    if(y == (long long)(y)) {
        y *= (x - 1);
        y /= 4;
        return (y == floorl(y));
    }
    return false;    
}

inline void solve() {
    for(int i = 2, p = 7; p <= 1e9 ; ++i, p += 3) {
        if(integral_area1(i)) sum += p;
    } 
    for(int i = 2, p = 5; p <= 1e9; ++i, p += 3) {
        if(integral_area2(i)) sum += p;
    }
    printf("%llu\n", sum);
}

int main() {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
