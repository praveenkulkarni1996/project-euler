//  Note : all acceptable numbers are of the form prime - 1
//  i have not used this optimization, that should bring the time
//  down from 36 seconds to about 5s.

#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;

const int n = 1e8;
vector<bool> accept (n + 1, true);
vector<bool> prime (n + 1, true);
inline void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i) {
        if(prime[i]) for(int j = i * i; j < n; j += i) {
            prime[j] = false;
        }
    } 
}
void solver() {
    sieve();
    for(int i = 0; i * i < n; ++i) {
        for(int j = i; i * j < n; ++j) {
            if(i + j > n) break;
            if(prime[i + j]) continue;
            else accept[i * j] = false;
        }
    }
    long long answer = 0;
    for(int i = 0; i < n; ++i) {
        if(accept[i]) answer += i;
    }
    printf("answer = %lld\n", answer);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
