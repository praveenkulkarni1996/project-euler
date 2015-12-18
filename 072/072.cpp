#include <iostream>
using namespace std;

const int N = (int)1e6;
int etf[N + 1];

void sieve() {
    for(int i = 0; i <= N; ++i) etf[i] = i;
    for(int i = 2; i <= N; ++i) {
        if(etf[i] == i) {
            for(int j = 1; i * j <= N; ++j) {
                etf[i * j] /= i;
                etf[i *j] *= i - 1;
            }
        }
    }
}
    
int main() {
    sieve();
    long long sum = 0;
    for(int i = 2; i <= N; ++i) 
        sum += etf[i];
    printf("%lld\n", sum);
}
