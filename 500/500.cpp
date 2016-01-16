#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int n = 74e5;
const int mod = 500500507;
const int limit = 2716;
vector<bool> prime (n, true);
set<int> primeset;

inline void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i) {
        if(prime[i]) for(int j = i * i; j < n; j += i) {
            prime[j] = false;
        }
    }
    for(int i = 2, m = 500500 ; i < n; ++i) if(prime[i]) {
        primeset.insert(i);
        if(--m == 0) break; 
    }
}

inline void solver() {
    sieve();
    long long answer = 1;
    int counter = 500500;
    while(counter--) {
        int num = *primeset.begin(); primeset.erase(num);
        answer = (answer * num) % mod;
        if (num < limit) primeset.insert(num * num);
    }
    printf("answer = %lld\n", answer);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
