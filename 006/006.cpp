#include <iostream>
#include <cstdio>
using namespace std;

inline void solver() {
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i <=100; ++i) sum1 += i * i;
    for(int i = 0; i <= 100; ++i) sum2 += i; sum2 *= sum2;
    printf("answer = %d\n", sum2 - sum1);
}
int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
