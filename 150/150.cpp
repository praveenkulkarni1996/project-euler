#include <iostream>
using namespace std;

const int n = 1000;
long long a[n + 2][n + 1];
long long s[n + 2][n + 1];
long long b[n + 2][n + 1];
inline void build() {
    memset(a, 0, sizeof(s));
    memset(s, 0, sizeof(s));
    memset(b, 0, sizeof(s));
    long long t = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            t = (615949 * t + 797807) % (1 << 20);
            a[i][j] = t - (1 << 19);
        }
    }    
}

inline void solver() {
    build();
    long long small = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            s[i][j] = a[i][j];
            b[i][j] = a[i][j] + a[i + 1][j] + a[i + 1][j + 1];
            small = min(small, min(s[i][j], b[i][j]));
        }
    }
    for(int h = 2; h < n ; ++h) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                s[i][j] = b[i][j];
                b[i][j] = a[i][j] + b[i + 1][j] + b[i + 1][j + 1] - s[i + 2][j + 1];
                small = min(small, b[i][j]);
            }
        }
    }
    printf("answer = %lld\n", small);
}


int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
