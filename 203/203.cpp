#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int n = 51;
long long c[n + 1][n + 1];
set<long long> q;
const int primeset[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int m = sizeof(primeset) / sizeof(primeset[0]);

inline void solver() {
    for(int i = 0; i < n; ++i) c[i][i] = c[i][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if(q.count(c[i][j]) == 0) {
                q.insert(c[i][j]);
            }
        }
    }
    long long answer = 0;
    for(long long qnum : q) {
        bool sqrfree = true;
        for(int i = 0; i < m; ++i) {
            long long p = primeset[i]; p *= p;
            if(qnum % p == 0) { sqrfree = false; break; }
        }
        if(sqrfree) { answer += qnum; } 
    } 
    printf("answer = %lld\n", 1 + answer);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
