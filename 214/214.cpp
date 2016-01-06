#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

// note that further analysis tells you that the maximum length of the chain is 25
// so len[] can be of type unsigned char
const int m = 25;
const int n = 40000000;
unsigned int etf[n];
unsigned char len[n];
long long answer = 0; 

inline void solver() {
    for(int i = 0; i < n; ++i) {
        etf[i] = i; len[i] = 0;
    }
    len[1] = 1;
    for(int i = 2; i < n; ++i) if(etf[i] == i) {
        for(int j = i; j < n; j += i) {
            etf[j] /= i;
            etf[j] *= i - 1;
        }
    }
    for(int i = 2; i < n; ++i) {
        len[i] = 1 + len[etf[i]] ;
    }
    for(int i = 2; i < n; ++i) if(etf[i] == i - 1 and len[i] == m) {
        answer += i;
    }
    printf("answer = %lld\n", answer);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
// SAMPLE OUTPUT:
// answer = 1677366278943
// time = 2.712176
