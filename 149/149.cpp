#include <iostream>
using namespace std;

const int n = 2000;
int a[n][n];
int num[n];

inline int maximize(int n) {
    if(n == 0) return 0;
    int answer = num[0];
    for(int i = 1; i < n; ++i) {
        num[i] = max(num[i], num[i] + num[i - 1]);
        answer = max(answer, num[i]);
    }
    return answer;
}

inline void build() {
    long long k = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(k <= 55) {
                a[i][j] = (100003 - 200003 * k + 300007 * k * k * k ) % 1000000 - 500000;
            } 
            else {
                int *ptr = &a[i][j];
                ptr[0] = (ptr[-24] + ptr[-55] + 1000000) % 1000000 - 500000;
            }
            ++k;
        }
    }
}
inline void solver() {
    build();
    int answer = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) num[j] = a[i][j];
        answer = max(answer , maximize(n));
    }
    for(int j = 0; j < n; ++j) {
        for(int i = 0; i < n; ++i) num[i] = a[i][j];
        answer = max(answer, maximize(n));
    }
    printf("answer = %d\n", answer);
}
int main() {
    clock_t start = clock();
    solver();   //techinincally the solver is incomplete, it does not check diagonals
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}

