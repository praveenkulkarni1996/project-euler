#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int n = 5000;     //  maximum prime
const int m = 1548137;  //  a number greater than the maximum sum possible
const unsigned long long mod = (unsigned long long) 1e16;

unsigned long long countsets[m + 1];
vector<bool> prime (m + 1, true);
vector<int> primeset;

void sieve () {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= m; ++i) if(prime[i]) for(int j = i * i ; j <= m; j += i) prime[j] = false;
    for(int i = 2; i <= m; ++i) if(prime[i]) primeset.push_back(i);
}

int main() {
    clock_t start = clock();
    sieve();
    memset(countsets, 0, sizeof(countsets));    countsets[0] = 1;

    for(int i = 0; i < primeset.size(); ++i) {
        int p = primeset[i];    if(p > n) break;
        for(int j = m ; j - p >= 0; --j) {
            countsets[j] += countsets[j - p];
            if(countsets[j] > mod) countsets[j] -=  mod;
        }
    }
    unsigned long long answer = 0;
    for(int i = 0; i < primeset.size(); ++i) {
        int p = primeset[i];
        if(p > m) break;
        answer += countsets[p];
        if(answer > mod) answer -= mod;
    }
    printf("%llu\n", answer);
    printf("time = %f\n", double(clock() - start) / CLOCKS_PER_SEC);
}
