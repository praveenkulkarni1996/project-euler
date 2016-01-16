#include <iostream>
#include <vector>
using namespace std;

const long long n = 2e9 + 1;
vector<bool> a (n, false);
vector<bool> b (n, false);
vector<bool> c (n, false);
vector<bool> d (n, false);

inline void solver() {
    for(long long num1 = 1; num1 * num1 <= n; ++num1) {
        for(int num2 = 1; num2 * num2 <= n; ++num2) {
            long long x = num1 * num1 + num2 * num2;
            if(x <= n) a[x] = true;
        }
    }
    for(long long num1 = 1; num1 * num1 <= n; ++num1) {
        for(long long num2 = 1; 2 * num2 * num2 <= n; ++num2) {
            long long x = num1 * num1 + 2 * num2 * num2;
            if(x <= n) b[x] = true;
        }
    }
    for(long long num1 = 1; num1 * num1 <= n; ++num1) {
        for(long long num2 = 1; 3 * num2 * num2 <= n; ++num2) {
            long long x = num1 * num1 + 3 * num2 * num2;
            if(x <= n) c[x] = true;
        }
    }
    for(long long num1 = 1; num1 * num1 <= n; ++num1) {
        for(long long num2 = 1; 7 * num2 * num2 <= n; ++num2) {
            long long x = num1 * num1 + 7 * num2 * num2;
            if(x <= n) d[x] = true;
        }
    }
    int answer = 0;
    for(int i = 0; i <= n; ++i) {
        if (d[i] and c[i] and b[i] and a[i])
            ++answer;
    }
    printf("answer = %d\n", answer);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
