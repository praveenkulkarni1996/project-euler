#include <iostream>
#include <vector>
using namespace std;

const int n = 1e6;
long long p[n + 1];

inline long long penta(int x) {
    return (x * 1LL * (3 * x - 1)) >> 1;
}

inline long long get_p(int x) {
    return x >= 0 ? p[x] : 0;
}
inline void solver() {
    p[0] = 1;
    for(int i = 1; i <= n; ++i) {
        p[i] = 0;
        int prod = 1;
        for(int j = 1; ; ++j) {
            int x = penta(j), y = penta(-j);
            if(x > i and y > i) break;
            p[i] += prod * (((get_p(i - x) + get_p(i - y)))) % n;
            prod *= -1;
        }
        if(p[i] % n == 0) {
            printf("answer = %d\n", i);
            return;
        }
    }
}
int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );

}
